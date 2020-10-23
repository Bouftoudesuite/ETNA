FROM debian:buster

RUN apt-get update -y
RUN apt-get install -y python3 python3-pip
RUN apt-get install -y docker docker.io runc
RUN apt-get install -y curl

COPY ./Dockerfile /app/Dockerfile
COPY ./requirements.txt /app/requirements.txt
COPY ./app.py /app/app.py

WORKDIR /app

RUN pip3 install -r requirements.txt

ENV FLASK_APP app.py

HEALTHCHECK CMD curl -f http://localhost:5000/ || exit 1

CMD [ "flask", "run", "--host=0.0.0.0", "--port=5000"]
