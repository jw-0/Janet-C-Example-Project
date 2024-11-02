# Find the shared library in the build directory
(import ./build/rectangle)

# Entry point for our program
(defn main [& args]
	(def initial-width 10)
	(def initial-height 5)
	(print "Creating a rectangle with width (" initial-width ") and height (" initial-height ")")
	(def rect (rectangle/new initial-width initial-height))
	(print "Width: " (rectangle/get-width rect))  
	(print "Height: " (rectangle/get-height rect))
	(print "Area: " (rectangle/area rect)) 
	(print "Perimeter: " (rectangle/perimeter rect))
	(print "Diagonal: " (rectangle/diagonal rect))


	(print "\nChanging width (20) and height (30)")
	(rectangle/set-width rect 20)
	(rectangle/set-height rect 30)
	(print "Width: " (rectangle/get-width rect))  
	(print "Height: " (rectangle/get-height rect))
	(print "Area: " (rectangle/area rect))
	(print "Perimeter: " (rectangle/perimeter rect))
	(print "Diagonal: " (rectangle/diagonal rect)) 


	(print "\nUsing set-properties to set width (3000) and height (2.5)")
	(rectangle/set-properties rect :width 3000 :height 2.5)
	(print "Width: " (rectangle/get-width rect))  
	(print "Height: " (rectangle/get-height rect))
	(print "Area: " (rectangle/area rect))
	(print "Perimeter: " (rectangle/perimeter rect))
	(print "Diagonal: " (rectangle/diagonal rect)) 


	(print "\nUsing set-properties to just set width (21.1)")
	(rectangle/set-properties rect :width 21.1)
	(print "Width: " (rectangle/get-width rect))  
	(print "Height: " (rectangle/get-height rect))
	(print "Area: " (rectangle/area rect))
	(print "Perimeter: " (rectangle/perimeter rect))
	(print "Diagonal: " (rectangle/diagonal rect)) 

	(print "\nDeleting rectangle.")
	(rectangle/free rect))