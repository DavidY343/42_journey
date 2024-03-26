#!/bin/bash
# Contar el número de ocurrencias de "died" en todo el archivo
ocurrencias=$(grep -o "died" infile | wc -l)

# Si el número de ocurrencias es igual a 1, verificar si "died" es la última palabra
if [ $ocurrencias -eq 1 ]; then
    # Obtener la última palabra del archivo
    ultima_palabra=$(tail -n 1 infile)
    
    # Verificar si "died" está presente en la última palabra del archivo
    if [ "$ultima_palabra" == *"died"* ]; then
        echo "A muerto un filosofo: $ultima_palabra"
    else
        echo "Un filosofo ha muerto, pero no es la última palabra del archivo."
    fi
else
    echo "Número de ocurrencias de 'died': $ocurrencias. No se puede determinar si es la última palabra."
fi

#for (( i=1; i<=200; i++ )); do
#    if [ $(grep -o "${i} is eating" infile | wc -l) -eq 2 ]; then
#        echo "La cadena '${i} is eating' aparece exactamente 7 veces en el archivo."
#    else
#        echo "La cadena '${i} is eating' no aparece 7 veces en el archivo."
#    fi
#done

# Inicializar la variable de iteración
i=1

# Usar un bucle while para iterar hasta que i sea mayor que 200
while [ $i -le 200 ]; do
    if [ $(grep -o "${i} is eating" infile | wc -l) -eq 2 ]; then
        echo "La cadena '${i} is eating' aparece exactamente 2 veces en el archivo."
    else
        echo "La cadena '${i} is eating' no aparece 2 veces en el archivo."
    fi
    
    # Incrementar i
    i=$((i + 1))
done