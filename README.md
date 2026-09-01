# Problema del Máximo Subarreglo

## 1. Implementación

Se implementaron tres soluciones para encontrar la suma máxima de un subarreglo:

- Solución cúbica: O(n³)
- Solución cuadrática: O(n²)
- Algoritmo de Kadane: O(n)

Las tres implementaciones trabajan sobre arreglos (`array`) de enteros.

Para verificar que las implementaciones fueran correctas, se generaron 100 arreglos pequeños de manera aleatoria, utilizando valores positivos y negativos.

En las 100 pruebas, las tres implementaciones obtuvieron el mismo resultado.

Para el arreglo de ejemplo:

```text
{10, 0, -8, 19, -1}
```

las tres soluciones obtuvieron:

```text
21
```

Por ejemplo, el subarreglo `{10, 0, -8, 19}` tiene suma:

```text
10 + 0 - 8 + 19 = 21
```

Por lo tanto, el resultado obtenido es correcto.

---

## 2. Medición de tiempos

Se realizaron mediciones duplicando el tamaño del arreglo:

```text
1000, 2000, 4000, 8000
```

Los resultados obtenidos fueron:

| n | O(n³) (s) | Razón | O(n²) (s) | Razón | O(n) Kadane (s) | Razón |
|---:|---:|---:|---:|---:|---:|---:|
| 1000 | 0.295652 | — | 0.000866 | — | 0.000005 | — |
| 2000 | 2.296504 | 7.77 | 0.003365 | 3.89 | 0.000010 | 1.93 |
| 4000 | 18.285243 | 7.96 | 0.014235 | 4.23 | 0.000019 | 1.93 |
| 8000 | 146.125844 | 7.99 | 0.053630 | 3.77 | 0.000038 | 1.97 |

### Análisis

Al duplicar el tamaño del arreglo, la solución O(n³) aumenta aproximadamente 8 veces. Esto coincide con el comportamiento esperado de una función cúbica.

La solución O(n²) aumenta aproximadamente 4 veces al duplicar n, lo cual coincide con el comportamiento cuadrático.

Finalmente, Kadane aumenta aproximadamente 2 veces al duplicar n, confirmando su comportamiento lineal O(n).

Por lo tanto, las mediciones experimentales coinciden con los órdenes de crecimiento teóricos:

```text
O(n³) → razón ≈ 8
O(n²) → razón ≈ 4
O(n)  → razón ≈ 2
```

---

## 3. Predicción para n = 10^8

Para realizar la predicción se utilizó la medición obtenida con n = 8000.

Como:

```text
10^8 / 8000 = 12500
```

se utilizaron los siguientes factores de crecimiento:

- O(n³): 12500³
- O(n²): 12500²
- O(n): 12500

### O(n³)

La última medición fue:

```text
T(8000) = 146.125844 segundos
```

Por lo tanto:

```text
T(10^8) ≈ 146.125844 × 12500³
```

La predicción es aproximadamente:

```text
285 402 039 062 500 segundos
```

Esta cantidad de tiempo es muy superior a un minuto, por lo que no se ejecutó esta versión para n = 10^8.

### O(n²)

La última medición fue:

```text
T(8000) = 0.053630 segundos
```

Entonces:

```text
T(10^8) ≈ 0.053630 × 12500²
```

La predicción es aproximadamente:

```text
8 379 687.5 segundos
```

Esto corresponde aproximadamente a 97 días, por lo que tampoco se ejecutó esta versión para n = 10^8.

### O(n) - Kadane

La última medición fue:

```text
T(8000) = 0.000038 segundos
```

Entonces:

```text
T(10^8) ≈ 0.000038 × 12500
```

La predicción es:

```text
0.475 segundos
```

Como la predicción es menor a un minuto, esta fue la única implementación ejecutada para n = 10^8.

### Predicho vs. medido (n = 10^8, solo Kadane)

| | Tiempo |
|---|---:|
| Predicho | 0.475 s |
| Medido | 0.647641 s |

---

## 4. Resultados y conclusiones

Los resultados experimentales muestran claramente la diferencia entre las tres complejidades.

La solución O(n³) presenta un crecimiento muy rápido. Al duplicar n, su tiempo aumenta aproximadamente 8 veces.

La solución O(n²) es considerablemente más rápida que la cúbica, pero también se vuelve impracticable para tamaños muy grandes.

Kadane, con complejidad O(n), presenta un crecimiento lineal y es la única solución de las tres que resulta viable para un arreglo de tamaño 10^8.

Las mediciones experimentales confirman los órdenes de crecimiento teóricos estudiados en clase.

Para n = 10^8 se predijo que:

| Algoritmo | Tiempo estimado | ¿Se ejecuta? |
|---|---:|:---:|
| O(n³) | 285 402 039 062 500 s | No |
| O(n²) | 8 379 687.5 s | No |
| Kadane O(n) | 0.475 s | Sí |

La principal conclusión es que, aunque las tres soluciones producen el mismo resultado, la elección del algoritmo es fundamental cuando el tamaño de entrada es grande.

---

## 5. Entorno de ejecución

**Lenguaje:** C++

**Compilador:** g++ 13.3.0

**Procesador:** Intel(R) Core(TM) i7-10700 CPU @ 2.90GHz

**Memoria RAM:** 7.6 GiB

**Sistema operativo:** Ubuntu 24.04.4 LTS
