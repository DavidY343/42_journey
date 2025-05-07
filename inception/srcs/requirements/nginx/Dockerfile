FROM alpine:3.19

RUN apk update && apk add --no-cache nginx openssl

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/setup_tls.sh /setup/setup_tls.sh

RUN sh /setup/setup_tls.sh

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
