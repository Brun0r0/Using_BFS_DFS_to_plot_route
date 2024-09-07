Trabalho realizado no 2º semestre do curso de Engenharia de Computação. Visa a implementação de um algoritmo de busca em largura e de busca em profundidade em um mapa de caracteres que simula ilhas.

Significado de cada caractere: 
"." -> Água |
"#" -> Terra |
"L" -> Sua localização |
"X" -> Localização do tesouro |

Para utilizar corretamente tem-se que colocar o tamanho do mapa da seguinte forma:

"altura" "comprimento"
"mapa"

Como está presente no arquivo "exemplo.txt"

Se a localização "L" e a Localização "X" estiverem na mesma ilha é realizada a busca em profundidade e a busca em largura e imprime o caminho. Caso o tesouro esteja em outra ilha, imprime o tamanho da menor e da maior ilha e a impossibilidade de realizar o movimento.
