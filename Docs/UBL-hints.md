M190 S80        ; Греем стол
M104 S230       ; Греем хот-енд

M502            ; Сбрасываем текущие настройки
M500            ; Сохраняем текущие настройки
M501            ; Выводим текущие настройки
M851 Z-0.4      ; Установить смещение по Z

G28
G29 P1          ; Do automated probing of the bed.
G29 T           ; View the Z compensation values.
G29 S1          ; Save UBL mesh points to EEPROM.
G29 A           ; Activate the UBL System.
M500            ; Сохраняем текущие настройки. WARNING: UBL will be active at power up, before any `G28`.

G28 
G26 B60 H210 F1.75 L0.4 S1 
 – B температура нагрева стола
 – H температура нагрева экструдера
 – F диаметр филамента
 – L высота слоя 
 - S диаметр сопла

;------------------------------------------
G90                 ; Absolute positioning
G1 Z10 F100         ; Safe Z moving
G1 X110 Y110 F1000  ; Move to centre
M48 P4 V2 E L2      ; Проверить работу датчика уровня


;------------------------------------------
;--- Setup and initial probing commands ---
;------------------------------------------
M502            ; Reset settings to configuration defaults...
M500            ; ...and Save to EEPROM. Use this on a new install.
M501            ; Read back in the saved EEPROM.  

G28             ; Home XYZ.
G29 P1          ; Do automated probing of the bed.
G29 P2 B T      ; Manual probing of locations USUALLY NOT NEEDED!!!!
G29 P3 T        ; Repeat until all mesh points are filled in.

G29 T           ; View the Z compensation values.
G29 S1          ; Save UBL mesh points to EEPROM.
G29 F 10.0      ; Set Fade Height for correction at 10.0 mm.
G29 A           ; Activate the UBL System.
M500            ; Save current setup. WARNING: UBL will be active at power up, before any `G28`.

;---------------------------------------------
;--- Fine Tuning of the mesh happens below ---
;---------------------------------------------
                
G29 P4 T        ; Move nozzle to 'bad' areas and fine tune the values if needed
                ; Repeat G26 and G29 P4 T  commands as needed.

G29 S1          ; Save UBL mesh values to EEPROM.
M500            ; Resave UBL's state information.

;----------------------------------------------------
;--- Use 3-point probe to transform a stored mesh ---
;----------------------------------------------------
G29 L1          ; Load the mesh stored in slot 1 (from G29 S1)
G29 J           ; No size specified on the J option tells G29 to probe the specified 3 points
                ; and tilt the mesh according to what it finds.

