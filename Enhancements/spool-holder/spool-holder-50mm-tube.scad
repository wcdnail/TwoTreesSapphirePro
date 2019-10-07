use <../nb.scad>

$fn=256;

*spool_50mm_tube_mount();
spool_50mm_tube_clamp();

module spool_50mm_tube_mount() {
  difference() {
    difference() {
      difference() {
        difference() {
          cylinder(d1=62,d2=54,h=10);
          translate([0, 0, 6.4]) color("red") cylinder(d=50.3, h=100);
        }
        translate([0, 0, -20]) color("blue") cylinder(d=8.1,h=40);
      }
      translate([0, 0, -2.5]) color("green") nutHole(8, tolerance = 0.3);
    }
    translate([0, 13, -70]) cylinder(d=5,h=140);
    translate([0, -13, -70]) cylinder(d=5,h=140);
  }
}

module spool_50mm_tube_clamp(cz=7) {
  idia=50.4;
  id1=idia;
  id2=idia + 1;
  odia=54;
  od1=odia;
  od2=odia + 2;
  bcz=1.2;
  difference() {
    difference() {
      difference() {
        difference() {
          cylinder(d1=od1, d2=od2, h=cz);
          translate([0, 0, bcz]) color("red") cylinder(d1=id1, d2=id2, h=cz*2);
        }
        translate([0, 0, -20]) color("blue") cylinder(d=8.1,h=40);
      }
    }
  }
}
