#!/bin/sh
set -e

# Inicializar la base de datos si no existe
if [ ! -d /var/lib/mysql/mysql ]; then
  echo "Initializing MariaDB data directory..."
  mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql > /dev/null

  echo "Starting MariaDB for setup..."
  mysqld --user=mysql --bootstrap <<-EOF
    FLUSH PRIVILEGES;
    CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '$(cat ${MYSQL_PASSWORD_FILE})';
    GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
    SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$(cat ${MYSQL_ROOT_PASSWORD_FILE})');
    FLUSH PRIVILEGES;
EOF
fi

echo "Starting MariaDB server..."
exec mysqld --user=mysql
