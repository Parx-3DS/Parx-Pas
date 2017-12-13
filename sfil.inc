//the sfil biblioteck, to a Pascal feat :: NinjaHax 2DS & 3DS platform
//
// Copyright (c) 2015 .. 2017 Kenneth Dwayne Lee PhD.
// all rights reserved
//
// FreePascal just couldn't sexlive with out, a very bad case of Xerpi's   

  {*
   * @file sfil.h
   * @author PhD. Sergi Granell (xerpi)
   * @date 2 April 2015
   * @brief sfillib header
    }

  {*
   * @brief Loads a PNG image from the SD card
   * @param filename the path of the image to load
   * @param place where to allocate the texture
   * @return a pointer to the newly created texture/image
    }
  function sfil_load_PNG_file(const filename:pchar; place:sf2d_place):Psf2d_texture;cdecl;external;

  {*
   * @brief Loads a PNG image from a memory buffer
   * @param buffer the pointer of the memory buffer to load the image from
   * @param place where to allocate the texture
   * @return a pointer to the newly created texture/image
    }
  function sfil_load_PNG_buffer(const buffer:pointer; place:sf2d_place):Psf2d_texture;cdecl;external;

  {*
   * @brief Loads a JPG/JPEG image from the SD card
   * @param filename the path of the image to load
   * @param place where to allocate the texture
   * @return a pointer to the newly created texture/image
    }
  function sfil_load_JPEG_file(const filename:pchar; place:sf2d_place):Psf2d_texture;cdecl;external;

  {*
   * @brief Loads a JPG/JPEG image from a memory buffer
   * @param buffer the pointer of the memory buffer to load the image from
   * @param buffer_size the size of the memory buffer
   * @param place where to allocate the texture
   * @return a pointer to the newly created texture/image
    }
  function sfil_load_JPEG_buffer(const buffer:pointer; buffer_size:culong; place:sf2d_place):Psf2d_texture;cdecl;external;

  {*
   * @brief Loads a BMP image from the SD card
   * @param filename the path of the image to load
   * @param place where to allocate the texture
   * @return a pointer to the newly created texture/image
    }
  function sfil_load_BMP_file(const filename:pchar; place:sf2d_place):Psf2d_texture;cdecl;external;

  {*
   * @brief Loads a BMP image from a memory buffer
   * @param buffer the pointer of the memory buffer to load the image from
   * @param place where to allocate the texture
   * @return a pointer to the newly created texture/image
    }
  function sfil_load_BMP_buffer(const buffer:pointer; place:sf2d_place):Psf2d_texture;cdecl;external;

