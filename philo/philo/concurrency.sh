#!/bin/sh

# Definir el número de ejecuciones
num_ejecuciones=200

# Nombre del archivo de salida
output_file="output.txt"

# Bucle para ejecutar el programa y verificar la condición después de cada ejecución
i=1
while [ $i -le $num_ejecuciones ]; do
    # Ejecutar el programa y redirigir la salida al archivo
    ./philo 4 201 100 100 > infile

    # Contar el número de ocurrencias de "died" en todo el archivo
    ocurrencias=$(grep -o "died" infile | wc -l)

    # Si el número de ocurrencias es igual a 1, verificar si "died" es la última palabra
    if [ $ocurrencias -eq 1 ]; then
        # Obtener la última palabra del archivo
        ultima_palabra=$(tail -n 1 infile)

        # Verificar si "died" está presente en la última palabra del archivo
        if echo "$ultima_palabra" | grep -q "died"; then
            echo "Ejecución $i: Un filósofo ha muerto: $ultima_palabra" >> $output_file
        else
            echo "Ejecución $i: Un filósofo ha muerto, pero no es la última palabra del archivo." >> $output_file
        fi
    else
        echo "Ejecución $i: Número de ocurrencias de 'died': $ocurrencias. No se puede determinar si es la última palabra." >> $output_file
    fi

    i=$((i+1))
done

# Verificar si el archivo contiene las líneas que no deben aparecer
if grep -q "Número de ocurrencias de 'died'" "$output_file" || grep -q "Un filósofo ha muerto, pero no es la última palabra del archivo." "$output_file"; then
    echo "El archivo contiene líneas no deseadas."
else
    echo "El archivo no contiene líneas no deseadas."
fi
