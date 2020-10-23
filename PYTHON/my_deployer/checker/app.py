__author__ = "habi_a"

from flask import Flask, jsonify, request

import docker

app = Flask(__name__)

client = docker.from_env()


@app.route('/')
def hello():
    return jsonify('Hello, World!')

@app.route('/containers/')
def show_containers():
    results = []
    all = request.args.get('all')
    if all == "true" or all == "True":
        containers = client.containers.list(all=True)
    else:
        containers = client.containers.list(all=False)
    for container in containers:
        uptime = container.status if container.status == "stopped" else container.attrs['Created']
        result = {
            "name": container.name,
            "short_hash": container.short_id,
            "image": container.image.tags[0],
            "uptime": uptime,
            "published_ports": container.attrs['HostConfig']['PortBindings'],
            "volumes": container.attrs['Mounts']
        }
        results.append(result)
    return jsonify(results)

@app.route('/containers/<id>')
def show_container_by_id(id):
    container = client.containers.get(id)
    uptime = container.status if container.status == "stopped" else container.attrs['Created']
    result = {
        "name": container.name,
        "short_hash": container.short_id,
        "image": container.image.tags[0],
        "uptime": uptime,
        "published_ports": container.attrs['HostConfig']['PortBindings'],
        "volumes": container.attrs['Mounts']
    }
    return jsonify(result)
