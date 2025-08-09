FROM alpine:3.19

# Instalar dependencias (incluyendo curl)
RUN apk update && apk add --no-cache \
    php82 php82-fpm php82-mysqli php82-curl php82-gd \
    php82-mbstring php82-opcache php82-json php82-session \
    php82-zlib php82-dom php82-exif wget netcat-openbsd \
    curl less mariadb-client \
    php82-phar

# Instalar WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Descargar WordPress
RUN mkdir -p /var/www/html && \
    wget https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz -C /var/www/html --strip-components=1 && \
    rm latest.tar.gz

RUN sed -i 's/^listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/' /etc/php82/php-fpm.d/www.conf

COPY tools/ /setup/

EXPOSE 9000

ENTRYPOINT ["sh", "/setup/entrypoint.sh"]
