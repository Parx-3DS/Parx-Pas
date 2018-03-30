//the Pascal translation of libctru 1.0.0 headers files for the nintendo 3ds platform
//
// Copyright (c) 2016 Kenny D. Lee
// all rights reserved
//


  {*
   * @brief Allocates a 0x80-byte aligned buffer.
   * @param size Size of the buffer to allocate.
   * @return The allocated buffer.
    }

  function vramAlloc(size:longint):pointer;cdecl;external;

  {*
   * @brief Allocates a buffer aligned to the given size.
   * @param size Size of the buffer to allocate.
   * @param alignment Alignment to use.
   * @return The allocated buffer.
    }
  function vramMemAlign(size:longint; alignment:longint):pointer;cdecl;external;

  {*
   * @brief Reallocates a buffer.
   * Note: Not implemented yet.
   * @param mem Buffer to reallocate.
   * @param size Size of the buffer to allocate.
   * @return The reallocated buffer.
    }
  function vramRealloc(mem:pointer; size:longint):pointer;cdecl;external;

  {*
   * @brief Frees a buffer.
   * @param mem Buffer to free.
    }
  procedure vramFree(mem:pointer);cdecl;external;

  {*
   * @brief Gets the current VRAM free space.
   * @return The current VRAM free space.
    }
  function vramSpaceFree:longint;cdecl;external;


  {*
   * @brief Allocates a 0x80-byte aligned buffer.
   * @param size Size of the buffer to allocate.
   * @return The allocated buffer.
    }

  function linearAlloc(size:LongWord):pointer;cdecl;external;

  {*
   * @brief Allocates a buffer aligned to the given size.
   * @param size Size of the buffer to allocate.
   * @param alignment Alignment to use.
   * @return The allocated buffer.
    }
  function linearMemAlign(size:longint; alignment:LongWord):pointer;cdecl;external;

  {*
   * @brief Reallocates a buffer.
   * Note: Not implemented yet.
   * @param mem Buffer to reallocate.
   * @param size Size of the buffer to allocate.
   * @return The reallocated buffer.
    }
  function linearRealloc(mem:pointer; size:longint):pointer;cdecl;external;

  {*
   * @brief Frees a buffer.
   * @param mem Buffer to free.
    }
  procedure linearFree(mem:pointer);cdecl;external;

  {*
   * @brief Gets the current linear free space.
   * @return The current linear free space.
    }
  function linearSpaceFree:longint;cdecl;external;

  {*
   * @brief Allocates a page-aligned buffer.
   * @param size Size of the buffer to allocate.
   * @return The allocated buffer.
    }

  function mappableAlloc(size:longint):pointer;cdecl;external;

  {*
   * @brief Frees a buffer.
   * @param mem Buffer to free.
    }
  procedure mappableFree(mem:pointer);cdecl;external;

  {*
   * @brief Gets the current mappable free space.
   * @return The current mappable free space.
    }
  function mappableSpaceFree:longint;cdecl;external;

