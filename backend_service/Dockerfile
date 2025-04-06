FROM fedora:39

RUN dnf install -y gcc-c++ make cmake poco-devel postgresql-devel && dnf clean all

WORKDIR /app

COPY . .

RUN cmake . && make

CMD ["./backend_service"]
