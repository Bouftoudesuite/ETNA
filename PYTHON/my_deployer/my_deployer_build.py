#!/usr/bin/env python

"""Build services functions"""

__author__ = "habi_a"

import paramiko


def build(client: paramiko.client, service: str):
    print("--- My Deployer Builder ---")
    if service == "":
        build_checker(client)
        build_tester(client)
    elif service == "checker":
        build_checker(client)
    elif service == "tester":
        build_tester(client)
    else:
        print("service unknown")
    return


def build_checker(client: paramiko.client):
    print("-> building checker")
    client.exec_command('mkdir /tmp/checker')
    ftp_client=client.open_sftp()
    ftp_client.put('./checker/Dockerfile', '/tmp/checker/Dockerfile')
    ftp_client.put('./checker/requirements.txt', '/tmp/checker/requirements.txt')
    ftp_client.put('./checker/app.py', '/tmp/checker/app.py')
    ftp_client.close()
    stdin, stdout, stderr = client.exec_command('docker build -t checker:latest /tmp/checker')
    exit_status = stdout.channel.recv_exit_status() # Blocking call
    if exit_status == 0:
        print("Done.")
    else:
        print("Error while building", exit_status)


def build_tester(client: paramiko.client):
    print("-> building tester")
    print("Done.")
