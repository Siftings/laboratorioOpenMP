# Laboratorios OpenMP

Diversos laboratorios haciendo uso de la API OpenMP, para la ejecucion de programas de manera paralela.

## Instalar compilador

En MacOS si se intenta utilizar gcc utiliza por defecto Clang, el cual no tiene soporte nativo de OpenMP, por lo que se sugiere intalar gcc de GNU por medio de Homebrew.

- **macOS**: GCC (`brew install gcc`)
- **Ubuntu/Linux**: GCC (`sudo apt install gcc`)

## Como compilar 

### macOS
```bash
make CC=gcc-15
```

### Ubuntu/Linux
```bash
make
```

### Compilar un laboratorio específico
```bash
# macOS
make Lab01Daza CC=gcc-15

# Ubuntu
make Lab01Daza
```

### Limpiar ejecutables
```bash
make clean
```

---
**Autor**: Juan David Daza Caro  
**Materia**: Sistemas Operativos  
**Docente**: John Corredor PhD.
**Universidad**: Pontificia Universidad Javeriana
