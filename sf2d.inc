//the SF2D biblioteck, to a Pascal feat :: NinjaHax 2DS & 3DS platform
//
// Copyright (c) 2015 .. 2017 Kenneth Dwayne Lee PhD.
// all rights reserved
//
// FreePascal just couldn't sexlive with out, a very bad case of Xerpi's   

{$ifdef 3dsintf}

  {*
   * @file sf2d.h
   * @author PhD. Sergi Granell (xerpi)   
   * @date 22 March 2015
   * @brief sf2dlib header
    }

  { Defines }
  {*
   * @brief Creates a new RGBA8 color
   * @param r the red component of the color to create
   * @param g the green component of the color to create
   * @param b the blue component of the color to create
   * @param a the alpha component of the color to create
    }
  function RGBA8(r,g,b,a : u8) : u32;  
  function RGBA8_GET_R(c : u32) : u8;  
  function RGBA8_GET_G(c : u32) : u8;  
  function RGBA8_GET_B(c : u32) : u8;  
  function RGBA8_GET_A(c : u32) : u8;  

  {*
   * @brief Default size of the GPU commands FIFO buffer
    }
  const
    SF2D_GPUCMD_DEFAULT_SIZE = $80000;    
  {*
   * @brief Default size of the temporary memory pool
    }
    SF2D_TEMPPOOL_DEFAULT_SIZE = $80000;    
  {*
   * @brief Default depth (Z coordinate) to draw the textures to
    }
    SF2D_DEFAULT_DEPTH = 0.5;
    {*
     * @brief Represents a texture format
      }

    type
      sf2d_texfmt =  Longint;
      Const
        TEXFMT_RGBA8 = 0;
        TEXFMT_RGB8 = 1;
        TEXFMT_RGB5A1 = 2;
        TEXFMT_RGB565 = 3;
        TEXFMT_RGBA4 = 4;
        TEXFMT_IA8 = 5;
        TEXFMT_I8 = 7;
        TEXFMT_A8 = 8;
        TEXFMT_IA4 = 9;
        TEXFMT_I4 = 10;
        TEXFMT_A4 = 11;
        TEXFMT_ETC1 = 12;
        TEXFMT_ETC1A4 = 13;
    {*
     * @brief Represents a direction for drawing a gradient
      }

    type
      sf2d_gradient_dir =  Longint;
      Const
        SF2D_TOP_TO_BOTTOM = 0;
        SF2D_LEFT_TO_RIGHT = 1;
    {*
     * @brief Data allocated on the RAM or VRAM
      }
    {*< RAM allocated  }
    {*< VRAM allocated  }

    type
      sf2d_place =  Longint;
      Const
        SF2D_PLACE_RAM = 0;
        SF2D_PLACE_VRAM = 1;
    { Structs }
    {*
     * @brief Represents a two dimensional float vector
      }
    {*< First component of the vector  }
    {*< Second component of the vector  }

    type
      sf2d_vector_2f = record
          u : cfloat;
          v : cfloat;
        end;
    {*
     * @brief Represents a three dimensional float vector
      }
    {*< First component of the vector  }
    {*< Second component of the vector  }
    {*< Third component of the vector  }

      sf2d_vector_3f = record
          x : cfloat;
          y : cfloat;
          z : cfloat;
        end;
    {*
     * @brief Represents a vertex containing position (float)
     *        and color (unsigned int)
      }
    {*< Position of the vertex  }
    {*< Color of the vertex  }

      sf2d_vertex_pos_col = record
          position : sf2d_vector_3f;
          color : u32;
        end;
    {*
     * @brief Represents a vertex containing position and texture coordinates
      }
    {*< Position of the vertex  }
    {*< Texture coordinates of the vertex  }

      sf2d_vertex_pos_tex = record
          position : sf2d_vector_3f;
          texcoord : sf2d_vector_2f;
        end;
    {*
     * @brief Represents a texture
      }
    {*< citro3d texture object  }
    {*< Whether the texture is tiled or not  }
    {*< Actual texture width  }
    {*< Actual texture height  }

      sf2d_texture = record
          tex : C3D_Tex;
          tiled : cint;
          width : cint;
          height : cint;
        end;
    Psf2d_texture  = ^sf2d_texture;

    {*< citro3d render target object  }
    {*< Orthographic projection matrix for this target  }

      sf2d_rendertarget = record
          target : PC3D_RenderTarget;
          projection : C3D_Mtx;
        end;
     Psf2d_rendertarget  = ^sf2d_rendertarget;

    { Basic functions }
    {*
     * @brief Initializates the library
     * @return Whether the initialization has been successful or not
      }

    function sf2d_init:cint;cdecl;external;

    {*
     * @brief Initializates the library (with advanced settings)
     * @param gpucmd_size the size of the GPU FIFO
     * @param temppool_size the size of the temporary pool
     * @return Whether the initialization has been successful or not
      }
    function sf2d_init_advanced(gpucmd_size:cint; temppool_size:cint):cint;cdecl;external;

    {*
     * @brief Finishes the library
     * @return Whether the finalization has been successful or not
      }
    function sf2d_fini:cint;cdecl;external;

    {*
     * @brief Enables or disables the 3D
     * @param enable whether to enable or disable the 3D
      }
    procedure sf2d_set_3D(enable:cint);cdecl;external;

    {*
     * @brief Sets a transformation matrix to apply to vertices
     * @param mtx Transformation matrix (or NULL to disable it)
      }
    procedure sf2d_set_transform(mtx:PC3D_Mtx);cdecl;external;

    {*
     * @brief Starts a frame
     * @param screen target screen
     * @param side target eye (only for top screen)
      }
    procedure sf2d_start_frame(screen:gfxScreen_t; side:gfx3dSide_t);cdecl;external;

    {*
     * @brief Starts a frame bound to a rendertarget
     * @param target rendertarget to draw to
      }
    procedure sf2d_start_frame_target(target:Psf2d_rendertarget);cdecl;external;

    {*
     * @brief Ends a frame, should be called on pair with sf2d_start_frame
      }
    procedure sf2d_end_frame;cdecl;external;

    {*
     * @brief Swaps the framebuffers, should be called once after all the frames have been finished
      }
    procedure sf2d_swapbuffers;cdecl;external;

    {*
     * @brief Enables or disables the VBlank waiting
     * @param enable whether to enable or disable the VBlank waiting
      }
    procedure sf2d_set_vblank_wait(enable:cint);cdecl;external;

    {*
     * @brief Returns the FPS (frames per second)
     * @return the current FPS
      }
    function sf2d_get_fps:cfloat;cdecl;external;

    {*
     * @brief Allocates memory from a temporary pool. The pool will be emptied after a sf2d_swapbuffers call
     * @param size the number of bytes to allocate
      }
    function sf2d_pool_malloc(size:u32):pointer;cdecl;external;

    {*
     * @brief Allocates aligned memory from a temporary pool. Works as sf2d_pool_malloc
     * @param size the number of bytes to allocate
     * @param alignment the alignment to where allocate the memory
      }
    function sf2d_pool_memalign(size:u32; alignment:u32):pointer;cdecl;external;

    {*
     * @brief Allocates aligned memory for an array from a temporary pool. Works as sf2d_pool_malloc
     * @param nmemb the number of elements to allocate
     * @param size the size (and alignment) of each element to allocate
     * @note Unlike libc's calloc, this function does not initialize to 0,
     *       and returns a pointer aligned to size.
      }
    function sf2d_pool_calloc(nmemb:u32; size:u32):pointer;cdecl;external;

    {*
     * @brief Returns the temporary pool's free space
     * @return the temporary pool's free space
      }
    function sf2d_pool_space_free:cuint;cdecl;external;

    {*
     * @brief Empties the temporary pool
      }
    procedure sf2d_pool_reset;cdecl;external;

    {*
     * @brief Sets the screen clear color
     * @param color the color
      }
    procedure sf2d_set_clear_color(color:u32);cdecl;external;

    { Draw functions }
    {*
     * @brief Draws a line
     * @param x0 x coordinate of the first dot
     * @param y0 y coordinate of the first dot
     * @param x1 x coordinate of the second dot
     * @param y1 y coordinate of the sceond dot
         * @param width thickness of the line
     * @param color the color to draw the line
      }
    procedure sf2d_draw_line(x0:cfloat; y0:cfloat; x1:cfloat; y1:cfloat; width:cfloat; 
                color:u32);cdecl;external;

    {*
     * @brief Draws a rectangle
     * @param x x coordinate of the top left corner of the rectangle
     * @param y y coordinate of the top left corner of the rectangle
     * @param w rectangle width
     * @param h rectangle height
     * @param color the color to draw the rectangle
      }
    procedure sf2d_draw_rectangle(x:cint; y:cint; w:cint; h:cint; color:u32);cdecl;external;

    {*
     * @brief Draws a triangle
     * @param x1 x coordinate of a vertex of the triangle
     * @param y1 y coordinate of a vertex of the triangle
     * @param x2 x coordinate of a vertex of the triangle
     * @param y2 y coordinate of a vertex of the triangle
     * @param x3 x coordinate of a vertex of the triangle
     * @param y3 y coordinate of a vertex of the triangle
     * @param color the color to draw the triangle
      }
    procedure sf2d_draw_triangle(x1:cfloat; y1:cfloat; x2:cfloat; y2:cfloat; x3:cfloat; 
                y3:cfloat; color:u32);cdecl;external;

    {*
     * @brief Draws a rotated rectangle
     * @param x x coordinate of the top left corner of the rectangle
     * @param y y coordinate of the top left corner of the rectangle
     * @param w rectangle width
     * @param h rectangle height
     * @param color the color to draw the rectangle
     * @param rad rotation (in radians) to draw the rectangle
      }
    procedure sf2d_draw_rectangle_rotate(x:cint; y:cint; w:cint; h:cint; color:u32; 
                rad:cfloat);cdecl;external;

    {*
     * @brief Draws a rectangle
     * @param x x coordinate of the top left corner of the rectangle
     * @param y y coordinate of the top left corner of the rectangle
     * @param w rectangle width
     * @param h rectangle height
     * @param color1 the color at the start of the gradient
     * @param color2 the color at the end of the gradient
     * @param left_to_right determines which direction the gradient is in
      }
    procedure sf2d_draw_rectangle_gradient(x:cint; y:cint; w:cint; h:cint; color1:u32; 
                color2:u32; direction:sf2d_gradient_dir);cdecl;external;

    {*
     * @brief Draws a rotated rectangle
     * @param x x coordinate of the top left corner of the rectangle
     * @param y y coordinate of the top left corner of the rectangle
     * @param w rectangle width
     * @param h rectangle height
     * @param color1 the color at the start of the gradient
     * @param color2 the color at the end of the gradient
     * @param left_to_right determines which direction the gradient is in
     * @param rad rotation (in radians) to draw the rectangle
      }
    procedure sf2d_draw_rectangle_gradient_rotate(x:cint; y:cint; w:cint; h:cint; color1:u32; 
                color2:u32; direction:sf2d_gradient_dir; rad:cfloat);cdecl;external;

    {*
     * @brief Draws a filled circle
     * @param x x coordinate of the center of the circle
     * @param y y coordinate of the center of the circle
     * @param radius the radius of the circle
     * @param color the color to draw the circle
      }
    procedure sf2d_draw_fill_circle(x:cint; y:cint; radius:cint; color:u32);cdecl;external;

    { Texture }
    {*
     * @brief Creates an empty texture.
     * The returned texture has the data allocated,
     * this means that the raw pixel data can be filled
     * just after the return.
     * @param width the width of the texture
     * @param height the height of the texture
     * @param pixel_format the pixel_format of the texture
     * @param place where to allocate the texture
     * @return a pointer to the newly created texture
     * @note Before drawing the texture, it needs to be tiled
     *       by calling sf2d_texture_tile32.
     *       The default texture params are both min and mag filters
     *       GPU_NEAREST, and both S and T wrappings GPU_CLAMP_TO_BORDER.
      }
    function sf2d_create_texture(width:cint; height:cint; pixel_format:sf2d_texfmt; place:sf2d_place):Psf2d_texture;cdecl;external;

    {*
     * @brief Creates an empty rendertarget.
     * Functions similarly to sf2d_create_texture.
     * @param width the width of the texture
     * @param height the height of the texture
     * @return a pointer to the newly created rendertarget
     * @note Before drawing the texture, it needs to be tiled
     *       by calling sf2d_texture_tile32.
     *       The default texture params are both min and mag filters
     *       GPU_NEAREST, and both S and T wrappings GPU_CLAMP_TO_BORDER.
      }
    function sf2d_create_rendertarget(width:cint; height:cint):Psf2d_rendertarget;cdecl;external;

    {*
     * @brief Frees a texture
     * @param texture pointer to the texture to freeze
      }
    procedure sf2d_free_texture(texture:Psf2d_texture);cdecl;external;

    {*
     * @brief Frees a rendertarget
     * @param target pointer to the rendertarget to free
      }
    procedure sf2d_free_target(target:Psf2d_rendertarget);cdecl;external;

    {*
     * @brief Clears a rendertarget to the specified color
     * @param target pointer to the rendertarget to clear
      }
    procedure sf2d_clear_target(target:Psf2d_rendertarget; color:u32);cdecl;external;

    {*
     * @brief Fills an already allocated texture from a RGBA8 source
     * @param dst pointer to the destination texture to fill
     * @param rgba8 pointer to the RGBA8 data to fill from
     * @param source_w width (in pixels) of the RGAB8 source
     * @param source_h height (in pixels) of the RGAB8 source
      }
    procedure sf2d_fill_texture_from_RGBA8(dst:Psf2d_texture; rgba8:pointer; source_w:cint; source_h:cint);cdecl;external;

    {*
     * @brief Creates a texture and fills it from a RGBA8 memory source.
     * The returned texture is already tiled.
     * @param src_buffer pointer to the RGBA8 data to fill from
     * @param src_w width (in pixels) of the RGAB8 source
     * @param src_h height (in pixels) of the RGAB8 source
     * @param pixel_format the pixel_format of the texture to create
     * @param place where to allocate the texture
     * @return a pointer to the newly created, filled, and tiled texture
      }
    function sf2d_create_texture_mem_RGBA8(src_buffer:pointer; src_w:cint; src_h:cint; pixel_format:sf2d_texfmt; place:sf2d_place):Psf2d_texture;cdecl;external;

    {*
     * @brief Binds a texture to a GPU texture unit
     * @param texture the texture to bind
     * @param unit GPU texture unit to bind to
      }
    procedure sf2d_bind_texture(texture:Psf2d_texture; TexUnit:GPU_TEXUNIT);cdecl;external;

    {*
     * @brief Binds a texture to a GPU texture unit with a constant color
     * @param texture the texture to bind
     * @param unit GPU texture unit to bind to
     * @param color the color the bind with the texture
      }
    procedure sf2d_bind_texture_color(texture:Psf2d_texture; TexUnit:GPU_TEXUNIT; color:u32);cdecl;external;

    {*
     * @brief Changes the texture params (filters and wrapping)
     * @param texture the texture to change the params
     * @param params the new texture params to use. You can use the
     *        GPU_TEXTURE_[MIN,MAG]_FILTER and GPU_TEXTURE_WRAP_[S,T]
     *        macros as helpers.
      }
    procedure sf2d_texture_set_params(texture:Psf2d_texture; params:u32);cdecl;external;

    {*
     * @brief Returns the texture params
     * @param texture the texture to get the params
     * @return the current texture params of texture
      }
    function sf2d_texture_get_params(texture:Psf2d_texture):cint;cdecl;external;

    {*
     * @brief Draws a texture
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
      }
    procedure sf2d_draw_texture(texture:Psf2d_texture; x:cint; y:cint);cdecl;external;

    {*
     * @brief Draws a texture blended with a color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_blend(texture:Psf2d_texture; x:cint; y:cint; color:u32);cdecl;external;

    {*
     * @brief Draws a texture with rotation around a hotspot
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
     * @param center_x the x position of the hotspot
     * @param center_y the y position of the hotspot
      }
    procedure sf2d_draw_texture_rotate_hotspot(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat; center_x:cfloat; 
                center_y:cfloat);cdecl;external;

    {*
     * @brief Draws a texture with rotation around a hotspot with a color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
     * @param center_x the x position of the hotspot
     * @param center_y the y position of the hotspot
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_rotate_hotspot_blend(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat; center_x:cfloat; 
                center_y:cfloat; color:u32);cdecl;external;

    {*
     * @brief Draws a texture with rotation around its center
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
      }
    procedure sf2d_draw_texture_rotate(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat);cdecl;external;

    {*
     * @brief Draws a texture with rotation around its center with color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_rotate_blend(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat; color:u32);cdecl;external;

    {*
     * @brief Draws a scaled texture with rotation around its hotspot
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
     * @param x_scale the x scale
     * @param y_scale the y scale
     * @param center_x the x position of the hotspot
     * @param center_y the y position of the hotspot
      }
    procedure sf2d_draw_texture_rotate_scale_hotspot(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat; scale_x:cfloat; 
                scale_y:cfloat; center_x:cfloat; center_y:cfloat);cdecl;external;

    {*
     * @brief Draws a scaled texture with rotation around its hotspot with color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
     * @param x_scale the x scale
     * @param y_scale the y scale
     * @param center_x the x position of the hotspot
     * @param center_y the y position of the hotspot
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_rotate_scale_hotspot_blend(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat; scale_x:cfloat; 
                scale_y:cfloat; center_x:cfloat; center_y:cfloat; color:u32);cdecl;external;

    {*
     * @brief Draws a part of a texture
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param tex_x the starting point (x coordinate) where to start drawing
     * @param tex_y the starting point (y coordinate) where to start drawing
     * @param tex_w the width to draw from the starting point
     * @param tex_h the height to draw from the starting point
      }
    procedure sf2d_draw_texture_part(texture:Psf2d_texture; x:cint; y:cint; tex_x:cint; tex_y:cint; 
                tex_w:cint; tex_h:cint);cdecl;external;

    {*
     * @brief Draws a part of a texture with color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param tex_x the starting point (x coordinate) where to start drawing
     * @param tex_y the starting point (y coordinate) where to start drawing
     * @param tex_w the width to draw from the starting point
     * @param tex_h the height to draw from the starting point
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_part_blend(texture:Psf2d_texture; x:cint; y:cint; tex_x:cint; tex_y:cint; 
                tex_w:cint; tex_h:cint; color:u32);cdecl;external;

    {*
     * @brief Draws a texture with scaling
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param x_scale the x scale
     * @param y_scale the y scale
      }
    procedure sf2d_draw_texture_scale(texture:Psf2d_texture; x:cint; y:cint; x_scale:cfloat; y_scale:cfloat);cdecl;external;

    {*
     * @brief Draws a texture with scaling with color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param x_scale the x scale
     * @param y_scale the y scale
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_scale_blend(texture:Psf2d_texture; x:cint; y:cint; x_scale:cfloat; y_scale:cfloat; 
                color:u32);cdecl;external;

    {*
     * @brief Draws a part of a texture, with scaling
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param tex_x the starting point (x coordinate) where to start drawing
     * @param tex_y the starting point (y coordinate) where to start drawing
     * @param tex_w the width to draw from the starting point
     * @param tex_h the height to draw from the starting point
     * @param x_scale the x scale
     * @param y_scale the y scale
      }
    procedure sf2d_draw_texture_part_scale(texture:Psf2d_texture; x:cfloat; y:cfloat; tex_x:cfloat; tex_y:cfloat; 
                tex_w:cfloat; tex_h:cfloat; x_scale:cfloat; y_scale:cfloat);cdecl;external;

    {*
     * @brief Draws a part of a texture, with scaling, with color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param tex_x the starting point (x coordinate) where to start drawing
     * @param tex_y the starting point (y coordinate) where to start drawing
     * @param tex_w the width to draw from the starting point
     * @param tex_h the height to draw from the starting point
     * @param x_scale the x scale
     * @param y_scale the y scale
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_part_scale_blend(texture:Psf2d_texture; x:cfloat; y:cfloat; tex_x:cfloat; tex_y:cfloat; 
                tex_w:cfloat; tex_h:cfloat; x_scale:cfloat; y_scale:cfloat; color:u32);cdecl;external;

    {*
     * @brief Draws a part of a texture, with rotation and scaling
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
     * @param tex_x the starting point (x coordinate) where to start drawing
     * @param tex_y the starting point (y coordinate) where to start drawing
     * @param tex_w the width to draw from the starting point
     * @param tex_h the height to draw from the starting point
     * @param x_scale the x scale
     * @param y_scale the y scale
      }
    procedure sf2d_draw_texture_part_rotate_scale(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat; tex_x:cint; 
                tex_y:cint; tex_w:cint; tex_h:cint; x_scale:cfloat; y_scale:cfloat);cdecl;external;

    {*
     * @brief Draws a part of a texture, with rotation, scaling and color
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param rad rotation (in radians) to draw the texture
     * @param tex_x the starting point (x coordinate) where to start drawing
     * @param tex_y the starting point (y coordinate) where to start drawing
     * @param tex_w the width to draw from the starting point
     * @param tex_h the height to draw from the starting point
     * @param x_scale the x scale
     * @param y_scale the y scale
     * @param color the color to blend with the texture
      }
    procedure sf2d_draw_texture_part_rotate_scale_blend(texture:Psf2d_texture; x:cint; y:cint; rad:cfloat; tex_x:cint; 
                tex_y:cint; tex_w:cint; tex_h:cint; x_scale:cfloat; y_scale:cfloat; 
                color:u32);cdecl;external;

    {*
     * @brief Draws a texture blended in a certain depth
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param z the depth to draw the texture to
     * @note The z parameter is a value in the [-32768, +32767] range,
     *       where -32768 is the deepest and +32767 the toppest.
     *       By default, the textures are drawn at z = 0.
     *       Keep in mind that this function won't do
     *       Order-independent transparency (OIT), so you should use fully
     *       opaque textures to get good results.
      }
    procedure sf2d_draw_texture_depth(texture:Psf2d_texture; x:cint; y:cint; z:csshort);cdecl;external;

    {*
     * @brief Draws a texture blended in a certain depth
     * @param texture the texture to draw
     * @param x the x coordinate to draw the texture to
     * @param y the y coordinate to draw the texture to
     * @param z the depth to draw the texture to
     * @param color the color to blend with the texture
     * @note The z parameter is a value in the [-32768, +32767] range,
     *       where -32768 is the deepest and +32767 the toppest.
     *       By default, the textures are drawn at z = 0.
     *       Keep in mind that this function won't do
     *       Order-independent transparency (OIT), so you should use fully
     *       opaque textures to get good results.
      }
    procedure sf2d_draw_texture_depth_blend(texture:Psf2d_texture; x:cint; y:cint; z:csshort; color:u32);cdecl;external;

    {*
     * @brief Draws the currently-bound texture using custom texture coordinates
     * @param left the left coordinate of the texture to start drawing
     * @param top the top coordinate of the texture to start drawing
     * @param width the width to draw from the starting left coordinate
     * @param height the height to draw from the starting top coordinate
     * @param u0 the U texture coordinate of the left vertices
     * @param v0 the V texture coordinate of the top vertices
     * @param u1 the U texture coordinate of the right vertices
     * @param v1 the V texture coordinate of the bottom vertices
      }
    procedure sf2d_draw_quad_uv_current(left:cfloat; top:cfloat; right:cfloat; bottom:cfloat; u0:cfloat; 
                v0:cfloat; u1:cfloat; v1:cfloat);cdecl;external;

    {*
     * @brief Like sf2d_draw_quad_uv_current, but binds the texture
     * @param texture the texture to draw
     * }
    procedure sf2d_draw_quad_uv(texture:Psf2d_texture; left:cfloat; top:cfloat; right:cfloat; bottom:cfloat; 
                u0:cfloat; v0:cfloat; u1:cfloat; v1:cfloat);cdecl;external;

    {*
     * @brief Like sf2d_draw_quad_uv_current, but binds the texture with the given blend color
     * @param texture the texture to draw
     * @param color the color to blend the texture with
     * }
    procedure sf2d_draw_quad_uv_blend(texture:Psf2d_texture; left:cfloat; top:cfloat; right:cfloat; bottom:cfloat; 
                u0:cfloat; v0:cfloat; u1:cfloat; v1:cfloat; color:u32);cdecl;external;

    {*
     * @brief Changes a pixel of the texture
     * @param texture the texture to change the pixel
     * @param x the x coordinate to change the pixel
     * @param y the y coordinate to change the pixel
     * @param new_color the new color to set to the pixel at (x, y)
      }
    procedure sf2d_set_pixel(texture:Psf2d_texture; x:cint; y:cint; new_color:u32);cdecl;external;

    {*
     * @brief Gets a pixel of the texture
     * @param texture the texture to get the pixel
     * @param x the x coordinate to get the pixel
     * @param y the y coordinate to get the pixel
     * @return the pixel at (x, y)
      }
    function sf2d_get_pixel(texture:Psf2d_texture; x:cint; y:cint):u32;cdecl;external;

    {*
     * @brief Tiles a texture
     * @param texture the texture to tile
      }
    procedure sf2d_texture_tile32(texture:Psf2d_texture);cdecl;external;

    {*
     * @brief Sets the scissor test
     * @param mode the test mode (disable, invert or normal)
     * @param x the starting x coordinate of the scissor
     * @param y the starting y coordinate of the scissor
     * @param w the width of the scissor rectangle
     * @param h the height of the scissor rectangle
     * @note This function should be called after sf2d_start_frame.
     *       The scissor will remain active until the sf2d_end_frame call.
      }
    procedure sf2d_set_scissor_test(mode:GPU_SCISSORMODE; x:u32; y:u32; w:u32; h:u32);cdecl;external;

    {*
     * @brief Returns the current screen (latest call to sf2d_start_frame)
     * @note The returned value can be GFX_TOP or GFX_BOTTOM.
      }
    function sf2d_get_current_screen:gfxScreen_t;cdecl;external;

    {*
     * @brief Returns the current screen side (latest call to sf2d_start_frame)
     * @note The returned value can be GFX_LEFT or GFX_RIGHT.
      }
    function sf2d_get_current_side:gfx3dSide_t;cdecl;external;

{$endif 3dsintf}

{$ifdef 3dsimpl}  

  function RGBA8(r,g,b,a: u8) : u32;
  begin
    RGBA8:=((a and $FF) shl 24) or ((b and $FF) shl 16) or ((g and $FF) shl 8) or ((r and $FF) shl 0);
  end;

  function RGBA8_GET_R(c : u32) : u8;
  begin
    RGBA8_GET_R:=(c shr 0) and $FF;
  end;

  function RGBA8_GET_G(c : u32) : u8;
  begin
    RGBA8_GET_G:=(c shr 8) and $FF;
  end;

  function RGBA8_GET_B(c : u32) : u8;
  begin
    RGBA8_GET_B:=(c shr 16) and $FF;
  end;
 
  function RGBA8_GET_A(c : u32) : u8;
  begin
    RGBA8_GET_A:=(c shr 24) and $FF;
  end;
  
{$endif 3dsimpl}

// Dr. Sergi Granell, Thank-You
//
// Your computer research, I dare say is an " Insperation to all " whom view!
//
// Kirk: if the 3DS linux disto needs of the many, out way the pocketbooks of the (perl .. asm .. pascal)? 
// Spock: $exlive long & ThreeDS, computer foster ...
//
