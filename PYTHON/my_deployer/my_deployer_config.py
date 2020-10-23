#!/usr/bin/env python

"""Config docker functions"""

__author__ = "habi_a"

import paramiko


def config(client: paramiko.client, service: str):
    """check if docker-ce 19.03 is installed and operate"""
    print("--- My Deployer Config ---")
    channel = client.invoke_shell()
    stdin = channel.makefile('wb')
    stdout = channel.makefile('rb')
    stdin.write('''
        if ! command -v docker &> /dev/null
        then
            echo "0"
        elif ! docker --version | grep -q "19.03"
        then
            echo "1"
        else
            echo "2"
        fi
        exit
    ''')
    output = stdout.readlines()[-3].decode("utf-8").strip()
    stdout.close()
    stdin.close()
    if output == "0":
        install_docker(client)
    elif output == "1":
        upgrade_docker(client)
    elif output == "2":
        print("Docker-ce 19.03 is already installed")
    else:
        print("Cannot find docker version installed")
    return


def install_docker(client: paramiko.client):
    """install docker-ce 19.03"""
    print("-> installing docker")
    channel = client.invoke_shell()
    stdin = channel.makefile('wb')
    stdout = channel.makefile('rb')
    stdin.write('''
        sudo apt-get update -y
        sudo apt-get install \
            apt-transport-https \
            ca-certificates \
            curl \
            gnupg-agent \
            software-properties-common
        curl -fsSL https://download.docker.com/linux/debian/gpg | sudo apt-key add -
        sudo add-apt-repository \
            "deb [arch=amd64] https://download.docker.com/linux/debian \
            $(lsb_release -cs) \
            stable"
        sudo apt-get update -y
        sudo apt-get install docker-ce=5:19.03.13~3-0~debian-buster \
            docker-ce-cli=5:19.03.13~3-0~debian-buster containerd.io
        exit
    ''')
    print("Done.")
    stdout.close()
    stdin.close()
    return


def upgrade_docker(client: paramiko.client):
    """install docker-ce 19.03"""
    print("-> upgrading docker to 19.03")
    channel = client.invoke_shell()
    stdin = channel.makefile('wb')
    stdout = channel.makefile('rb')
    stdin.write('''
        sudo apt-get update -y
        sudo apt-get install docker-ce=5:19.03.13~3-0~debian-buster \
            docker-ce-cli=5:19.03.13~3-0~debian-buster containerd.io
        exit
    ''')
    print("Done.")
    stdout.close()
    stdin.close()
    return
