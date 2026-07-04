
r -= 0.5

var color = make_colour_hsv(r*25,255,255)
draw_circle_colour(x,y,r,color,color,false)

if(!r)
	instance_destroy()
