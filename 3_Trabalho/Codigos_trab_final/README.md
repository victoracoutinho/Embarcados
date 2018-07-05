# Programas a instalar
**CHDK PTP para Raspbian**: binário encontra-se no diretório `chdkptp-r795_raspi`.

**CHDK**: deve ser instalado em uma câmera Canon PowerShot. Os aqruivos são
específicos para cada modelo de câmera.

**MBROLA**: o pacote principal precisa ser compilado a partir do arquivo **.dsc**
disponível nos repositórios do raspbian, mas as vozes já estão compiladas. O
pacote resultante da compilação, em formato **.deb** encontra-se no diretório
`mbrola_compilar`. Uma das vozes foi instalada com `apt install mbrola-br1`.

**Tesseract OCR**: o pacote principal e o para cada língua já estão no repositório
do Raspbian GNU/Linux. Instalar a partir do gerenciador de pacotes `APT`. O
pacote principal foi instalado por `apt install tesseract-ocr`. O reconhecimento
de caracteres em português é instalado por `tesseract-ocr-por`.

**Imagemagick**: tambén encontra-se em formato de pacote compilado no 
repositório do Raspbian. Também deve ser instalado pelo `APT`. Instalou-se no
sistema com o comando `apt install --no-install-recommends imagemagick`.

**Espeak-ng**: encontra-se também já compilado no repositório do Raspbian.
Foi instalado através do comando `apt install espeak-ng`.
