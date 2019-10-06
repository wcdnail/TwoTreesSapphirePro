
sideWidth = 4;
side      = [sideWidth, sideWidth, sideWidth];
XLength   = 100;
YLength   = 100;

translate([-XLength/2, -YLength/2, 0]) {
  cube(side+[XLength-sideWidth, 0, 0]);
  cube(side+[0, YLength-sideWidth, 0]);
}
