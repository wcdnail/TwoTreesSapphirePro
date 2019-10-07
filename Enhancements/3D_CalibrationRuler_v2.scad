/*
3D Calibration Ruler v2.0

Updated with hole gauge on Y Axis.

Created by Rich Cattell (Thingiverse ID:RichieC)
*/

use <Write.scad>

//X Ruler
translate([0,0,0]) rotate([0,0,0]) Ruler();

//Y Ruler
difference()
	{
	translate([124,22,0]) rotate([0,0,90]) Ruler();
	//Holes
	translate([111,119,-1]) cylinder(r=10/2,h=5,$fn=60);
	translate([111,108,-1]) cylinder(r=9/2,h=5,$fn=60);
	translate([111,98,-1]) cylinder(r=8/2,h=5,$fn=60);
	translate([111,89,-1]) cylinder(r=7/2,h=5,$fn=60);
	translate([111,81,-1]) cylinder(r=6/2,h=5,$fn=60);
	translate([111,74,-1]) cylinder(r=5/2,h=5,$fn=60);
	translate([111,68,-1]) cylinder(r=4/2,h=5,$fn=60);	
	translate([111,63,-1]) cylinder(r=3/2,h=5,$fn=60);	
	translate([111,59,-1]) cylinder(r=2/2,h=5,$fn=60);	
	translate([111,56,-1]) cylinder(r=1/2,h=5,$fn=60);	

}
	//Text for Holes
	translate([105.5,45,1]) rotate([0,0,90]) write("mm -",h=3,t=2);
	translate([105.5,117,1]) rotate([0,0,90]) write("10",h=3,t=2);
	translate([105.5,107,1]) rotate([0,0,90]) write("9",h=3,t=2);
	translate([105.5,97.5,1]) rotate([0,0,90]) write("8",h=3,t=2);
	translate([105.5,88,1]) rotate([0,0,90]) write("7",h=3,t=2);
	translate([105.5,80,1]) rotate([0,0,90]) write("6",h=3,t=2);
	translate([105.5,73,1]) rotate([0,0,90]) write("5",h=3,t=2);
	translate([105.5,67,1]) rotate([0,0,90]) write("4",h=3,t=2);
	translate([105.5,62,1]) rotate([0,0,90]) write("3",h=3,t=2);
	translate([105.5,58,1]) rotate([0,0,90]) write("2",h=3,t=2);
	translate([105.5,55,1]) rotate([0,0,90]) write("1",h=3,t=2);

//Center & XYZ Markings
translate([101,0,0]) cube([23,23,2]);
translate([101,2,1]) write(" X",h =6,t=2);
translate([122,16,1]) rotate([0,0,90]) write("Y",h=6,t=2);
translate([105,26,3]) rotate([90,0,90]) write("Z",h=6,t=2);

//Title
translate([5,13,1]) write("3D Calibration Ruler v2",h=5,t=2);

//Z Tower
translate([102,19,0]) cube([3,22,104]);
difference() 
	{
	translate([80,19,0]) cube([22,3,104]);
	//Z Axis Holes
	translate([91,23,10]) rotate([90,0,0]) cylinder(r=10/2,h=5,$fn=60);
	translate([91,23,23]) rotate([90,0,0]) cylinder(r=9/2,h=5,$fn=60);
	translate([91,23,35]) rotate([90,0,0]) cylinder(r=8/2,h=5,$fn=60);
	translate([91,23,46]) rotate([90,0,0]) cylinder(r=7/2,h=5,$fn=60);
	translate([91,23,56]) rotate([90,0,0]) cylinder(r=6/2,h=5,$fn=60);
	translate([91,23,65]) rotate([90,0,0]) cylinder(r=5/2,h=5,$fn=60);
	translate([91,23,73]) rotate([90,0,0]) cylinder(r=4/2,h=5,$fn=60);
	translate([91,23,80]) rotate([90,0,0]) cylinder(r=3/2,h=5,$fn=60);
	translate([91,23,86]) rotate([90,0,0]) cylinder(r=2/2,h=5,$fn=60);
	translate([91,23,91]) rotate([90,0,0]) cylinder(r=1/2,h=5,$fn=60);
	}

//Text for Z Axis Holes
translate([101,21,6]) rotate([90,270,0]) write("10mm",h=3,t=3);
translate([86,21,20]) rotate([90,270,0]) write("9mm",h=3,t=3);
translate([101,21,32]) rotate([90,270,0]) write("8mm",h=3,t=3);
translate([86,21,43]) rotate([90,270,0]) write("7mm",h=3,t=3);
translate([101,21,53]) rotate([90,270,0]) write("6mm",h=3,t=3);
translate([86,21,62]) rotate([90,270,0]) write("5mm",h=3,t=3);
translate([101,21,70]) rotate([90,270,0]) write("4mm",h=3,t=3);
translate([101,21,70]) rotate([90,270,0]) write("4mm",h=3,t=3);
translate([86,21,77]) rotate([90,270,0]) write("3mm",h=3,t=3);
translate([101,21,83]) rotate([90,270,0]) write("2mm",h=3,t=3);
translate([86,21,88]) rotate([90,270,0]) write("1mm",h=3,t=3);

//Z Ruler
translate([104,41,0]) rotate([0,270,180]) Ruler();

module Ruler()
{
	//The Ruler
	cube([104,22,2]);

	//mm marks
	for (x = [0 : 1 : 100])
		{
		translate([x+1,0,2]) cube([0.5,2,0.8]);
		}
	//5mm marks
	for (x = [0 : 5 : 100])
		{
		translate([x+1,0,2]) cube([0.5,3,1]);
		}
	//10mm marks & Numbers
	for (x = [0 : 10 : 100])
		{
		translate([x+1,0,2]) cube([0.5,5,1]);
		translate([x,6,2]) write(str(x/10),h=2,t=1);
		}
}
