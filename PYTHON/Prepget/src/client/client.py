#!/usr/bin/env python
# -*- coding: utf-8 -*-

import requests
import json
import argparse
import urllib
import os.path
import os
import hashlib
import tarfile
import sys


arg_ta = {
    'color': False,
    'verbose': False,
    'operation': None,
    'op_det': None,
    'script': False,
    'sc_det': None,
    'version': False,
    've_det': None,
}

uid = None
user = 0
result = []
r = g = y = b = n = "\033[00m"
s_l = "\n"

base_req_api = "172.16.2.76"
base_request_api = "http://" + base_req_api + "/public/index.php/api/"
request_api = base_request_api

file_gz = "/usr/local/prepget/tmp/paquet.tar.gz~"
log_uuid_f = "/usr/local/prepget/log_uuid"
uuid_f = "/usr/local/prepget/uuid"
installed_f = "/usr/local/prepget/installed"


def run():
    uuid()
    get_args()
    swch_colo()
    chck_arg()
    chck_oper()
    return


def uuid():
    global uid, user
    if os.path.isfile(uuid_f):
        file_w = open(uuid_f, "r")
        uid = file_w.read()
    else:
        uid = requests.get(base_request_api + "create/NULL/NULL/NULL")
        uid = json.loads(uid.text)
        uid = uid[0]["uuid"]
        file_w = open(uuid_f, "w")
        file_w.write(uid)
    file_w.close()
    uid_exist(uid, uuid_f)
    if os.path.isfile(log_uuid_f):
        file_w = open(log_uuid_f, "r")
        uid = file_w.read()
        file_w.close()
        user = 1
        uid_exist(uid, log_uuid_f)
    return


def uuid_user():
    global uid, user
    if user == 1:
        return
    if os.path.isfile(log_uuid_f):
        file_w = open(log_uuid_f, "r")
        uid = file_w.read()
        file_w.close()
        uid_exist(uuid_user, log_uuid_f)
    else:
        login = connect()
        mdp = raw_input("Enter a password: ")
        hash_object = hashlib.sha512(mdp)
        hex_dig = hash_object.hexdigest()
        uid = requests.get(base_request_api + "create/NULL/" + login + "/" + hex_dig)
        uid = json.loads(uid.text)
        uid = uid[0]["uuid"]
        if uid is None:
            print r + "Wrong Password.\n" + n
            uuid_user()
        else:
            to_print = g + "Right Password.\n" + n
            file_w = open(log_uuid_f, "w")
            file_w.write(uid)
            file_w.close()
            uid_exist(uuid_user, log_uuid_f)
            print to_print
    return


def uid_exist(fnc, file_d):
    global user
    check = requests.get(base_request_api + "search_uid/" + str(uid))
    check = json.loads(check.text)
    check = check[0]['uuid']
    if check is False:
        user = 0
        os.remove(file_d)
        fnc()


def connect():
    login = raw_input("Enter a login: ")
    to_ret = login
    exist = requests.get(base_request_api + "search_user/" + login)
    exist = json.loads(exist.text)[0]['exist']
    if exist is True:
        yes = raw_input("User " + b + login + n + " exist, connect [Y/N] ? ")
        if yes != 'Y' and yes != 'y':
            to_ret = connect()
    return to_ret


def get_args():
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument("-V", "--verbose", help="increase output verbosity", action="store_true")
    parser.add_argument("-c", "--color", help="add color", action="store_true")
    parser.add_argument("operation", help="operation for the package",
                        choices=["install", "update", "upload", "search", "delete"])
    parser.add_argument("package", help="name of the package | \"mines\"")
    parser.add_argument("-s", "--script", help="add script")
    parser.add_argument("-v", "--version", help="choose version")
    args = parser.parse_args()
    arg_ta['verbose'] = args.verbose
    arg_ta['color'] = args.color
    arg_ta['operation'] = args.operation
    arg_ta['op_det'] = args.package
    if arg_ta['operation'] != "upload":
        arg_ta['op_det'] = arg_ta['op_det'].replace("/", '')
    if args.script:
        arg_ta['script'] = True
        arg_ta['sc_det'] = args.script
    if args.version:
        arg_ta['version'] = True
        arg_ta['ve_det'] = args.version.replace("/", '')
    return


def chck_arg():
    arg_op = {
        'color',
        'script',
        'version',
        'verbose',
    }
    for key_1 in arg_ta:
        value = arg_ta[key_1]
        if key_1 in arg_op and value is True:
            log_error('active', key_1)
    for key_1 in arg_ta:
        value = arg_ta[key_1]
        if key_1 in arg_op and value is False:
            log_error('n_active', key_1)
    return


def chck_oper():
    op_aut = {
        "install": [install, "download"],
        "update": [update, "download"],
        "upload": [upload, "upload"],
        "search": [search, "search"],
        "delete": [delete, "delete"]
    }
    key_1 = arg_ta['operation']
    if key_1 in op_aut:
        global request_api
        request_api += op_aut[str(key_1)][1] + "/" + str(uid) + "/"
        request_api += arg_ta['op_det']
        if arg_ta['ve_det'] is not None:
            request_api += "/" + str(arg_ta['ve_det'])
        if arg_ta['op_det'] == "mine":
            if arg_ta['operation'] == "search":
                request_api = base_request_api + "search_depot/" + str(uid)
        op_aut[str(key_1)][0]()
    return


def requete_get():
    log_error('request', base_req_api)
    global result
    result = requests.get(request_api)
    if arg_ta['verbose'] is True:
        print format_t(result.text)
    result = json.loads(result.text)
    if 'Login' in result[0]:
        log_error("n_uid", "")
        sys.exit()
    return


def format_t(text):
    tab = ["[", "]", "\"", "\'"]
    for char in tab:
        text = text.replace(char, '')
    text = " " + text.replace(",", "\n")
    text = text.replace("}", "\n }")
    text = text.replace("{", "{\n ")
    return text


def install():
    if arg_ta['op_det'] == "mine":
        show_installed()
        return
    requete_get()
    to_print = s_l + "Downloading " + g + str(arg_ta['op_det']) + n
    to_print += " version: " + b + str(result[0]['version']) + s_l + n
    if result[0]['path'] is None:
        to_print = r + "\n" + arg_ta['op_det'].title() + " doesn't exist"
        to_print += (n + s_l) if arg_ta['version'] is False else (" at version " + str(arg_ta['ve_det']) + n + s_l)
        print to_print
        return
    name = result[0]['path'].split("/")[2]
    dep = name + "-v" + str(result[0]['version'])
    if os.path.isfile(installed_f):
        file_r = open(installed_f, "r")
        tab = file_r.read().split("|")
        file_r.close()
        for paq in tab[:-1]:
            if paq == dep:
                to_print = r + s_l + name + " already "
                to_print += "up to date" if arg_ta['version'] is False else "under version " + str(result[0]['version'])
                print to_print + s_l + n
                return
    print to_print
    path = "http://" + base_req_api + "/" + result[0]['path']
    urllib.urlretrieve(path, file_gz)
    tab = []
    if os.path.isfile(installed_f):
        file_r = open(installed_f, "r")
        tab = file_r.read().split("|")
    if dep not in tab:
        file_a = open(installed_f, "a")
        file_a.write(dep+"|")
        file_a.close()
    installation()
    return


def show_installed():
    to_print = r + s_l + "No paquet installed" + s_l + n
    if os.path.isfile(installed_f):
        to_print = y + s_l + "  Installed" + n + ":\n"
        file_r = open(installed_f, "r")
        tab = file_r.read().split("|")
        file_r.close()
        for paq in tab[:-1]:
            paq = paq.split("-v")
            to_print += "\t" + g + paq[0] + n + " version " + b + paq[1] + n + "\n"
    print to_print
    return


def installation():
    file_name = file_gz
    if os.path.isfile(file_name):
        if file_name.endswith("tar.gz~"):
            tar = tarfile.open(file_name, "r:gz")
            log_error("progress", "unzip")
            tar.extractall(path="/usr/local/prepget/paquet")
            log_error("finished", "unzip")
            content_names = tar.getnames()
            folder = "/usr/local/prepget/paquet/" + content_names[0]
            tar.close()
            log_error("progress", "Installation")
            if os.path.isdir(folder):
                if os.path.isfile(folder + "/dependencies.txt"):
                    os.system("while read i; do prepget install $i; done <" + folder + "/dependencies.txt")
                if os.path.isfile(folder + "/setup.sh"):
                    os.system("sh " + folder + "/setup.sh")
                    log_error("finished", "installation")
                else:
                    log_error("n_found", "setup.sh")
            else:
                log_error("n_found", "file")
    else:
        log_error("n_found", ".tar.gz")
    return


def update():
    global request_api
    if arg_ta['op_det'] != "all":
        to_print = r + s_l + str(arg_ta['op_det']) + " not installed" + s_l + n
        if os.path.isfile(installed_f):
            file_r = open(installed_f, "r")
            tab = file_r.read().split("|")
            file_r.close()
            for paq in tab[:-1]:
                paq = paq.split("-v")
                if paq[0] == str(arg_ta['op_det']):
                    request_api = base_request_api + "download/" + str(uid) + "/" + str(arg_ta['op_det'])
                    install()
                    to_print = g + "Update finished" + n
                    break
        print to_print
        return
    to_print = r + "No paquet installed" + n
    if os.path.isfile(installed_f):
        to_print = g + "Update finished" + n
        file_r = open(installed_f, "r")
        tab = file_r.read().split("|")
        for paq in tab[:-1]:
            paq = paq.split("-v")
            os.system("prepget install " + paq[0])
    print to_print
    return


def upload():
    if arg_ta['op_det'] == "mine":
        print r + "Upload do not take argument 'mine'" + n
        return
    if os.path.exists(arg_ta['op_det']) is False:
        print r + s_l + "The file doesn't exist." + s_l + n
        return
    uuid_user()
    if arg_ta['ve_det'] is None:
        print r + s_l + "You need to precise the version" + s_l + n
        return
    compress = "tar -czvf archive.tar.gz " + str(arg_ta['op_det'])
    compress += "&>/dev/null" if arg_ta['verbose'] is False else ''
    os.system(compress)
    name = arg_ta['op_det'].split("/")
    name = name[len(name) - 2] if arg_ta['op_det'][-1] == "/" else name[len(name) - 1]
    url = base_request_api + "upload/" + str(uid) + "/" + name + "/" + arg_ta['ve_det']
    file_r = {'file': open('archive.tar.gz', 'rb')}
    req = requests.post(url, files=file_r)
    to_print = s_l + "Your package was uploaded with the name: " + g + name + n
    to_print += " at version:" + b + str(arg_ta['ve_det']) + n + s_l
    req = json.loads(req.text)
    if 0 in req and 'Login' in req[0]:
        log_error("n_uid", "")
        return
    if 'version' in req[0]:
        to_print = r + s_l + "Package " + name + \
          " already exist at version: " + b + str(arg_ta['ve_det']) + n + s_l
    print to_print
    return


def search():
    global request_api
    to_print = r + s_l + arg_ta['op_det'].title() + " doesn't exist" + s_l + n
    if arg_ta['op_det'] == "mine":
        request_api = base_request_api + "search_depot/" + str(uid)
        to_print = r + s_l + "You uploaded nothing" + s_l + n
    requete_get()
    if "none" not in result[0] and result[0]['paquet'] is not None:
        to_print = y + s_l + "  Available" + n+":\n"
        for version in result:
            to_print += "\t" + g + version['paquet'] + n + \
                " version: " + b + str(version['version']) + n + "\n"
        if result[0]['version'] is None:
            to_print = r + s_l + result[0]['paquet'].title() + " version "\
                       + str(arg_ta['ve_det']) + " doesn't exist" + s_l + n
    print to_print
    return


def delete():
    if arg_ta['op_det'] == "mine":
        print r + "Delete do not take argument 'mine'" + n
        return
    uuid_user()
    requete_get()
    to_print = r + s_l + "DELETE failed" + s_l + n
    if result[0]["delete"] == 0:
        to_print = g + s_l + "DELETE succeed" + s_l + n
    print to_print
    return


def swch_colo():
    global s_l
    if arg_ta['verbose'] is False:
        s_l = ''
    if arg_ta['color'] is True:
        global r, g, y, b
        r = "\033[31m"
        g = "\033[32m"
        y = "\033[33m"
        b = "\033[34m"
    return


def log_error(stat, obj):
    if arg_ta['verbose'] is True:
        obj = b + obj + n
        log = {
            "n_found": r + " not " + y + "found",
            "finished": g + " is " + y + "finished",
            "progress": g + " in " + y + "progress",
            "n_ver": r + "You need to precise the version",
            "n_uid": r + "FATAL ERROR: uuid",
            "request": g + " is" + y + " requested",
            "error": r + " fatal Error",
            "n_active": r + " isn't" + y + " active",
            "active": g + " is " + y + "active"
        }
        log = obj + log[stat] + n + '.'
        print(log)
    return


run()
