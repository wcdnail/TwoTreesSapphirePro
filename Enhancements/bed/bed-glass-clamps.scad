include <../../../openscad/libs/nutsnbolts/cyl_head_bolt.scad>
include <../../../openscad/libs/nutsnbolts/materials.scad>

$fn=32;

side = 26;
height = 8.4;
boltHoleOffset = 2;
nutZ = 2.8;

fascX = 2.4;
fascY = 2.4;
fascZ = 3;

sliceX = boltHoleOffset;
sliceY = boltHoleOffset;
sliceDia = 38;

boltX = 12 + fascX + boltHoleOffset;
boltY = 12 + fascY + boltHoleOffset;
boltDia = 3.8;
springDia = 14;

cx = side + fascX;
cy = side + fascY;
cz = 5 + fascZ;

mcx = cx/1.4;
mcy = cy/1.4;
mcz = fascZ + height;
ms = 2.2;
nutScale = 0.04;

module bed_glass_clamp() {
  translate([-fascX, -fascY, -fascZ]) {
    difference() {
      union() {
        difference() {
          union() {
            cube([cx, cy, cz]);
            translate([-ms, -ms, 0]) cube([mcx, mcy, mcz]);
          }
          color("Blue") {
              translate([fascX, fascY, fascZ]) cube([cx, cy, cz*2]);
          }
          color("Red") {
            translate([cx + sliceX, cy + sliceY, 0]) rotate([0, 0, 45]) cube([cx*1.3, cy*2, cz*3], center=true);
          }
        }
        translate([boltX, boltY, 0]) cylinder(d=springDia, h=fascZ, $fn=64);
      }
      color("Red") {
        translate([boltX, boltY, -10]) cylinder(d=boltDia, h=50);
        translate([cx/2.8, cy/4, fascZ+nutZ+3/2]) rotate([90, 0, 0]) { cylinder(d=3.4, h=20); translate([0, 0, 7.2]) scale([1+nutScale, 1+nutScale, 1.6]) nut("M3"); }
        translate([-cx/4, cy/2.8, fascZ+nutZ+3/2]) rotate([0, 90, 0]) { cylinder(d=3.4, h=20);  translate([0, 0, 11]) rotate([0, 0, 90]) scale([1+nutScale, 1+nutScale, 1.6]) nut("M3"); }
      }
    }
  }
}

bed_glass_clamp();
