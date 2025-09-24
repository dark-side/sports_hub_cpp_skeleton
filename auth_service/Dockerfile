FROM debian:stable-slim

RUN apt-get update && apt-get install -y g++ make cmake libpoco-dev && apt-get clean

WORKDIR /app

COPY . .

RUN cmake . && cmake --build . --target auth_service

EXPOSE 8080

CMD ["./auth_service"]
