### Configuration.h
#### Конфигурация стола
  Наименование                                                      |Строка |Примечание
  ------------------------------------------------------------------|-------|----------
  Размер стола                                                      |   1088|
  Минимумы и максимумы стола                                        |   1094|
  Смещение "домашней" позиции MANUAL_X_HOME_POS MANUAL_Y_HOME_POS   |   1344|
  Z_SAFE_HOMING                                                     |   1357|
#### Конфигурация PID
  Наименование                                                      |Строка |Примечание
  ------------------------------------------------------------------|-------|----------
  PID                                                               |    502|M303 E0 S200 C8
  PIDTEMPBED                                                        |    554|M303 E-1 C8 S90
#### Остальные настройки
  Наименование                                                      |Строка |Примечание
  ------------------------------------------------------------------|-------|----------
  EXTRUDE_MAXLENGTH                                                 |    578|
  Константы драйверов                                               |    685|**Z_DRIVER_TYPE  TMC2208_STANDALONE** **E0_DRIVER_TYPE TMC2208_STANDALONE**
  Шаг и ускорение DEFAULT_AXIS_STEPS_PER_UNIT                       |    743|M302 P1 (disable cold extrusion checking)
  INVERT_ * _DIR                                                    |   1051|**INVERT_Z_DIR true** **INVERT_E0_DIR true**
  Сенсор окончания филамента FILAMENT_RUNOUT_SENSOR                 |   1138|ВЫКЛ
  Калибровка стола AUTO_BED_LEVELING_BILINEAR                       |   1202|ВЫКЛ
  Калибровка стола AUTO_BED_LEVELING_UBL                            |   1203|
  Калибровка стола MESH_BED_LEVELING                                |   1204|ВЫКЛ
  Калибровка стола MESH_BED_LEVELING настройки                      |   1297|ВЫКЛ
  Калибровка стола LCD_BED_LEVELING                                 |   1310|
  Калибровка стола LEVEL_BED_CORNERS                                |   1320|
  EEPROM_SETTINGS                                                   |   1444|Сохраняет в SPI Flash
  Настройка пред-нагрева PREHEAT_*                                  |   1480|PREHEAT_1_* : PET-G 215/75 PREHEAT_2_* : ABS 230/90
  Парковка хот-энда NOZZLE_PARK_FEATURE                             |   1502|
  Язык интерфейса LCD_LANGUAGE                                      |   1623|Русский
  Проверка целостности чтения файлов SD_CHECK_AND_RETRY             |   1683|
  "Пищалка" SPEAKER                                                 |   1755|При включении SPEAKER, **прошивка зависает!**
  
  
### Configuration_adv.h
  Наименование                                                      |Строка |Примечание
  ------------------------------------------------------------------|-------|----------
  X Y Z_HOME_BUMP_MM                                                |    522|
  HOME_AFTER_DEACTIVATE                                             |    666|
  M73 прогресс LCD_SET_PROGRESS_MANUALLY                            |    908|
  BABYSTEPPING                                                      |   1322|++
  Linear Advance                                                    |   1369|
  FWRETRACT                                                         |   1627|пока ВЫКЛ
  Расширенная пауза                                                 |   1686|
  FILAMENT_CHANGE_UNLOAD_LENGTH                                     |   1693|
