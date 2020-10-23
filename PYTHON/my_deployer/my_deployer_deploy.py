#!/usr/bin/env python

"""Deploy services functions"""

__author__ = "habi_a"

import paramiko


def deploy(client: paramiko.client, service: str):
    print("--- My Deployer Deployer ---")
    if service == "":
        deploy_checker(client)
        deploy_tester(client)
    elif service == "checker":
        deploy_checker(client)
    elif service == "tester":
        deploy_tester(client)
    else:
        print("service unknown")
    return


def container_exist(client: paramiko.client, image_name: str) -> bool:
    channel = client.invoke_shell()
    stdin = channel.makefile('wb')
    stdout = channel.makefile('rb')
    stdin.write('''
        if docker ps | grep -q "{}"
        then
            echo "1"
        else
            echo "0"
        fi
        exit
    '''.format(image_name))
    output = stdout.readlines()[-3].decode("utf-8").strip()
    stdout.close()
    stdin.close()
    if output == "1":
        return True
    return False


def deploy_checker(client: paramiko.client):
    print("-> deploying checker")
    if container_exist(client, "checker"):
        print("Container \"checker\" is already running")
        return
    client.exec_command('docker run -d --privileged=true -p 5000:5000 -v /var/run/docker.sock:/var/run/docker.sock checker')
    print("Done.")


def deploy_tester(client: paramiko.client):
    print("-> deploying tester")
    print("Done.")
