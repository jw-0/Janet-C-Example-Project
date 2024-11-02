(declare-project :name "rectangle")

# Create our native module
(def rect-module
  (declare-native
    # Set the module name
    :name "rectangle"
    # Set the source code for our module
    :source ["rectangle_bindings.cpp"]
    # Include the headers for our module
    :headers ["rectangle.h"]
    # Pass in the flags needed to compile it
    # I included a version of Janet but you can use your own include and lib if this isn't the latest
    :cppflags ["-fPIC" "-shared" "-Ijanet1.36/include" "-Ljanet1.36/lib/linux"]))

# Create our executable
(declare-executable
  :name "rect-exe"
  :entry "main.janet"
  # Make it depend on our rect module
  :deps [(rect-module :static)]
  :cflags ["-Ijanet1.36/include" "-Ljanet1.36/lib/linux"])

