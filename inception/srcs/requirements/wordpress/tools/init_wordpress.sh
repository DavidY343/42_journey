#!/bin/sh
set -e


until nc -z mariadb 3306; do
  echo "Waiting for MariaDB..."
  sleep 1
done

if [ ! -f /var/www/html/wp-config.php ]; then
  echo "Creating wp-config.php..."
  cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php

  sed -i "s/database_name_here/${MYSQL_DATABASE}/" /var/www/html/wp-config.php
  sed -i "s/username_here/${MYSQL_USER}/" /var/www/html/wp-config.php
  sed -i "s/password_here/${MYSQL_PASSWORD}/" /var/www/html/wp-config.php
  sed -i "s/localhost/mariadb/" /var/www/html/wp-config.php
fi

if ! wp core is-installed --path=/var/www/html --allow-root; then
  wp core install \
    --url=${DOMAIN_NAME} \
    --title="Proyecto Inception" \
    --admin_user=${WP_ADMIN_USER} \
    --admin_password=${WP_ADMIN_PASSWORD} \
    --admin_email=${WP_ADMIN_EMAIL} \
    --path=/var/www/html \
    --skip-email \
    --allow-root
  wp theme activate twentytwentyfour --path=/var/www/html --allow-root
    
  wp user create ${WP_USER} ${WP_EMAIL} \
  --user_pass=${WP_PASSWORD} \
  --role=author \
  --path=/var/www/html \
  --allow-root
fi

echo "Starting PHP-FPM..."
exec php-fpm82 --nodaemonize
