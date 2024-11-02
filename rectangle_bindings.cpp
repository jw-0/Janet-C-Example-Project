// rectangle_bindings.cpp
#include <janet.h>
#include "rectangle.h"


static Janet cfun_rectangle_new(int32_t argc, Janet *argv)
{
    // Ensure we have the required number of arguments (fixarity is when you have a set number of arguments, janet_arity for variable)
    // See: cfun_rectangle_set_properties
    janet_fixarity(argc, 2);
    // Extract arguments from argv
    double width = janet_getnumber(argv, 0);
    double height = janet_getnumber(argv, 1);
    // Create the rectangle and return it to Janet
    Rectangle *rect = new Rectangle(width, height);
    return janet_wrap_pointer(rect);
}


// Function to set properties of a Rectangle, uses variable arguments
static Janet cfun_rectangle_set_properties(int32_t argc, Janet *argv) 
{
    // For variable number of arguments we use janet_arity and set a min and max 
    janet_arity(argc, 1, 5);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);

    // Skip the values and just get the properties
    for (int32_t i = 1; i < argc; i += 2) 
    {
        // Extract the property string we're interested in
        const uint8_t *property = janet_getkeyword(argv, i);
        // Extract the value we're going to set it as

        double value = janet_getnumber(argv, i + 1);
        if (janet_cstrcmp(property, "width") == 0) 
        {
            rect->set_width(value);
        } 
        else if (janet_cstrcmp(property, "height") == 0) 
        {
            rect->set_height(value);
        }
        else 
        {
            janet_panicf("Unknown property: %s", property);
        }
    }
    return janet_wrap_nil();
}

// Function to get the area of a Rectangle
static Janet cfun_rectangle_area(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 1);
    // Get the pointer to our rectangle that we previously created
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    // Return the number to Janet (wrapped)
    return janet_wrap_number(rect->area());
}

// Function to get the perimeter of a Rectangle
static Janet cfun_rectangle_perimeter(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 1);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    return janet_wrap_number(rect->perimeter());
}

// Function to get the diagonal length of a Rectangle
static Janet cfun_rectangle_diagonal(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 1);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    return janet_wrap_number(rect->diagonal());
}

// Function to set the width of a Rectangle
static Janet cfun_rectangle_set_width(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 2);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    double width = janet_getnumber(argv, 1);
    rect->set_width(width);
    return janet_wrap_nil();
}

// Function to set the height of a Rectangle
static Janet cfun_rectangle_set_height(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 2);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    double height = janet_getnumber(argv, 1);
    rect->set_height(height);
    return janet_wrap_nil();
}

// Function to get the width of a Rectangle
static Janet cfun_rectangle_get_width(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 1);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    return janet_wrap_number(rect->get_width());
}

// Function to get the height of a Rectangle
static Janet cfun_rectangle_get_height(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 1);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    return janet_wrap_number(rect->get_height());
}

// Function to free the Rectangle instance
static Janet cfun_rectangle_free(int32_t argc, Janet *argv)
{
    janet_fixarity(argc, 1);
    Rectangle *rect = (Rectangle *)janet_getpointer(argv, 0);
    delete rect;
    // Return nothing
    return janet_wrap_nil();
}

// Register the functions
static const JanetReg cfuns[] = 
{
    {"new", cfun_rectangle_new, "(rectangle/new width height)\n\nCreates a new rectangle."},
    {"area", cfun_rectangle_area, "(rectangle/area rect)\n\nReturns the area of the rectangle."},
    {"perimeter", cfun_rectangle_perimeter, "(rectangle/perimeter rect)\n\nReturns the perimeter of the rectangle."},
    {"diagonal", cfun_rectangle_diagonal, "(rectangle/diagonal rect)\n\nReturns the diagonal length of the rectangle."},
    {"set-width", cfun_rectangle_set_width, "(rectangle/set-width rect width)\n\nSets the width of the rectangle."},
    {"set-height", cfun_rectangle_set_height, "(rectangle/set-height rect height)\n\nSets the height of the rectangle."},
    {"get-width", cfun_rectangle_get_width, "(rectangle/get-width rect)\n\nGets the width of the rectangle."},
    {"get-height", cfun_rectangle_get_height, "(rectangle/get-height rect)\n\nGets the height of the rectangle."},
    {"set-properties", cfun_rectangle_set_properties, "(rectangle/set-properties rect :property1 value1 [:property2 value2 ...])\n\nSets properties of the rectangle."},
    {"free", cfun_rectangle_free, "(rectangle/free rect)\n\nFrees the rectangle instance."},
    {NULL, NULL, NULL}
};

// Module entry point
extern "C" 
{
    JANET_MODULE_ENTRY(JanetTable *env)
    {
        janet_cfuns(env, "rectangle", cfuns);
    }
}
