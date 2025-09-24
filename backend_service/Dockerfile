FROM debian:stable-slim

RUN apt-get update && apt-get install -y g++ make cmake libpoco-dev && apt-get clean

WORKDIR /app

COPY . .

RUN cmake . && make

CMD ["./backend_service"]
