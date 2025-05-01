FROM gcc:latest

RUN apt-get update && apt-get install -y valgrind

WORKDIR /app

COPY *.c .
COPY test_all.sh .

RUN chmod +x test_all.sh

CMD ["./test_all.sh"]
