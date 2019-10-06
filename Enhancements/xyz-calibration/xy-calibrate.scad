
sideWidth = 10;
side      = [sideWidth, sideWidth, sideWidth];
XLength   = 100;
YLength   = 100;
ZLength   = 0;
textZOffs = -0.6;
textZSize = 3;
textSize  = sideWidth/1.5;

translate([-XLength/2, -YLength/2, 0]) {
  difference() {
    union() {
      cube(side+[XLength-sideWidth, 0, 0]);
      cube(side+[0, YLength-sideWidth, 0]);
      if (ZLength > sideWidth) {
        cube(side+[0, 0, ZLength-sideWidth]);
      }
    }
    color("Red") {
      translate([XLength/2, sideWidth/2, sideWidth + textZOffs]) linear_extrude(height=textZSize) text("X", size=textSize, halign="center", valign="center");
      translate([sideWidth/2, YLength/2, sideWidth + textZOffs]) rotate([0, 0, -90]) linear_extrude(height=textZSize) text("Y", size=textSize, halign="center", valign="center");
      if (ZLength > sideWidth) {
        translate([sideWidth/2, sideWidth/2, ZLength + textZOffs]) rotate([0, 0, -45]) linear_extrude(height=textZSize) text("Z", size=textSize, halign="center", valign="center");
      }
    }
  }
}
