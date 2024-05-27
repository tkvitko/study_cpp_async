FROM ubuntu:latest
LABEL tkvitko=""
RUN apt-get update
RUN apt-get install -y g++
WORKDIR /root/selection_sort_gpp/
COPY main.cpp .
RUN g++ main.cpp -o demo
CMD ["./demo"]
