g++ main.cpp -o main \
    -fcolor-diagnostics \
    -fansi-escape-codes \
    -Wall -I/opt/homebrew/Cellar/sfml/2.5.1_2/include \
    -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib \
    -lsfml-graphics -lsfml-system -lsfml-window \
    && ./main