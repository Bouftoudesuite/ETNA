#!/usr/bin/env python

"""Deploy services functions"""

__author__ = "habi_a"

import paramiko


def healthcheck(client: paramiko.client, service: str):
    print("--- My Deployer HealthChecker ---")
    if service == "":
        healthcheck_checker(client)
        healthcheck_tester(client)
    elif service == "checker":
        healthcheck_checker(client)
    elif service == "tester":
        healthcheck_tester(client)
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


def healthcheck_checker(client: paramiko.client):
    print("-> healthchecking checker")
    if not container_exist(client, "checker"):
        print("Container \"checker\" is not running")
        return
    stdin, stdout, stderr = client.exec_command("docker ps | grep checker | awk '{print $1}'")
    id = stdout.readline().strip()
    stdin, stdout, stderr = client.exec_command("docker inspect -f '{{.State.Health}}' " + id + " | awk '{print $1}'")
    health = stdout.readline().strip()[1:]
    print("status: " + health)
    if health == "unhealthy":
        print("-> restarting the container")
        stdin, stdout, stderr = client.exec_command("docker restart " + id)
        exit_status = stdout.channel.recv_exit_status()
        if exit_status != 0:
            print("Error while restarting", exit_status)
    print("Done.")


def healthcheck_tester(client: paramiko.client):
    print("-> healthchecking tester")
    print("Done.")
