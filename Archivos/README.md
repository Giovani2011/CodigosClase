# Sistema de Gestión de Accionistas (C++)

Este programa permite automatizar la lectura de Actas Constitutivas, la generación de perfiles de accionistas y la gestión de acceso seguro.

## Funcionalidades Principales

1.  **Lectura Automática (Opción 1):** Procesa `Acta.txt`, extrae datos de socios y genera perfiles individuales con claves encriptadas.
2.  **Acceso al Sistema (Opción 2):** Login seguro mediante cédula y clave.
3.  **Resumen Avanzado (Opción 3):** Muestra metadatos de la empresa y lista completa de accionistas detectados.
4.  **Validación Estricta:** Manejo obligatorio de formato de cédula (`XX.XXX.XXX`) y nacionalidad (`V/E`).

## Seguridad y Privacidad

Para proteger la información sensible, el sistema implementa:
- **Cifrado XOR Manual:** Las contraseñas nunca se guardan en texto plano. Se convierten a formato hexadecimal tras aplicar una operación XOR.
- **Variables de Entorno Ocultas:** Las claves de encriptación se cargan prioritariamente desde un archivo `.env` (no incluido en el código fuente).
- **Aislamiento de Datos:** Todos los perfiles se centralizan en la carpeta `output/`.

> **IMPORTANTE:** Por seguridad, asegúrese de crear un archivo `.env` en la raíz con la siguiente línea para personalizar su clave:
> `AES_KEY=SuClaveSecretaAqui`

## Estructura
- `LeerActaEmpresa.c++`: Código fuente documentado con comentarios detallados.
- `output/`: Almacén de perfiles encriptados.
- `Acta.txt`: Documento legal de entrada.

## Compilación
```bash
g++ LeerActaEmpresa.c++ -o LeerActaEmpresa
./LeerActaEmpresa
```
