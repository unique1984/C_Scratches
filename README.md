# C_Scratches

*Better than nothing, templates from me.*
-----

**08.08.2018** hex2rgb.c

* **Building**
	* gcc hex2rgb.c -o hex2rgb
* **Using**
	* ./hex2rgb FF00FF
```
yasin@uxn:~/C_Education/test$ ./hexTorgb FFFFFF
Hex24   #FFFFFF
RGB888 (255, 255, 255)

Hex16   #FFFF
RGB565 (63488, 2016, 31)
```
	*or*
```
yasin@uxn:~/C_Education/test$ ./hexTorgb 
Enter 24bit hexValue: FF00FF
Hex24   #FF00FF
RGB888 (255, 0, 255)

Hex16   #F81F
RGB565 (63488, 0, 31)
```
