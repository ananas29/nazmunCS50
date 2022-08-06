from cs50 import get_int

height = 0

while (height < 1 or height > 8):
    height = get_int("Height: ")


for row in range(1, height + 1):   #range(start, stop) misal height 4 maka hanya brjalan smpe 3, sehingga hrus ditambah 1
    print(' '* (height - row), end="") #karna row/hashes dan spasi (height - row) hrus berada disatu garis yg sama maka stlh spasi hrs ada end untuk mnghpus new line
    print('#' * row, end="")

    print(' ', end="") #tanda end="" untuk hapus new line yg otomatis dr python
    print('#' * row)

#langsung pake tanda kali (*) karna python lngng dapat membaca untun print tanda di sebelah kiri
#sebanyak value dlm variable sblh kanan