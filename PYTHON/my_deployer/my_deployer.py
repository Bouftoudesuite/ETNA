#!/usr/bin/env python

"""my_deployer"""

__author__ = "habi_a"

import argparse
import paramiko

import my_deployer_build
import my_deployer_config
import my_deployer_deploy
import my_deployer_healthcheck


def main():
    """handle args and run operation"""
    switcher = {
        "config": my_deployer_config.config,
        "build": my_deployer_build.build,
        "deploy": my_deployer_deploy.deploy,
        "healthcheck": my_deployer_healthcheck.healthcheck
    }
    parser = argparse.ArgumentParser()
    parser.add_argument("operation", help="operation for the package",
                        choices=["config", "build", "deploy", "healthcheck"])
    parser.add_argument("remote_ip", help="IP target")
    parser.add_argument("service", nargs='?', help='service target', default="")
    args = parser.parse_args()
    client = connect(args.remote_ip, 22, "debian", "p3ccbNzSATKn")
    func = switcher.get(args.operation)
    func(client, args.service)
    client.close()


def connect(ip: str, port: int, username: str, password: str) -> paramiko.client:
    client = paramiko.client.SSHClient()
    client.load_system_host_keys()
    client.connect(ip, port, username, password)
    return client


if __name__ == "__main__":
    main()
