//Pascal & the 3ds platform, useage of the citro3d
//
// Copyright (c) 2017 Kenny D. Lee
// all rights reserved.
//

{$ifdef 3dsintf}
    Type
    PC3D_Mtx  = ^C3D_Mtx;

 const
 
 //    M_TAU = 2*M_PI;  
 //C3D_AngleFromDegrees(_angle) ((_angle)*M_TAU/360.0f) }
 C3D_AspectRatioTop = (400.0 / 240.0); ///< Aspect ratio for 3DS top screen
 C3D_AspectRatioBot = (320.0 / 240.0); ///< Aspect ratio for 3DS bottom screen 
   
  {*
   * @brief Convert an angle from revolutions to radians
   * @param[in] _angle Proportion of a full revolution
   * @return Angle in radians
    }

  function C3D_Angle(_angle : double) : double;  

  {*
   * @brief Convert an angle from degrees to radians
   * @param[in] _angle Angle in degrees
   * @return Angle in radians
    }
    
    {*
     * @name Vector Math
     * @
      }
    {*
     * @brief Create a new FVec4
     * @param[in] x X-component
     * @param[in] y Y-component
     * @param[in] z Z-component
     * @param[in] w W-component
     * @return New FVec4
      }
    function FVec4_New(x:double; y:double; z:double; w:double):C3D_FVec;cdecl;external;

    {*
     * @brief Add two FVec4s
     * @param[in] lhs Augend
     * @param[in] rhs Addend
     * @return lhs+rhs (sum)
      }
    function FVec4_Add(lhs:C3D_FVec; rhs:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Subtract two FVec4s
     * @param[in] lhs Minuend
     * @param[in] rhs Subtrahend
     * @return lhs-rhs (difference)
      }
    function FVec4_Subtract(lhs:C3D_FVec; rhs:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Negate a FVec4
     * @note This is equivalent to `FVec4_Scale(v, -1)`
     * @param[in] v Vector to negate
     * @return -v
      }
    function FVec4_Negate(v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Scale a FVec4
     * @param[in] v Vector to scale
     * @param[in] s Scale factor
     * @return v*s
      }
    function FVec4_Scale(v:C3D_FVec; s:double):C3D_FVec;cdecl;external;

    {*
     * @brief Perspective divide
     * @param[in] v Vector to divide
     * @return v/v.w
      }
    function FVec4_PerspDivide(v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Dot product of two FVec4s
     * @param[in] lhs Left-side FVec4
     * @param[in] rhs Right-side FVec4
     * @return lhs∙rhs
      }
    function FVec4_Dot(lhs:C3D_FVec; rhs:C3D_FVec):double;cdecl;external;

    {*
     * @brief Magnitude of a FVec4
     * @param[in] v Vector
     * @return ‖v‖
      }
    function FVec4_Magnitude(v:C3D_FVec):double;cdecl;external;

    {*
     * @brief Normalize a FVec4
     * @param[in] v FVec4 to normalize
     * @return v/‖v‖
      }
    function FVec4_Normalize(v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Create a new FVec3
     * @param[in] x X-component
     * @param[in] y Y-component
     * @param[in] z Z-component
     * @return New FVec3
      }
    function FVec3_New(x:double; y:double; z:double):C3D_FVec;cdecl;external;

    {*
     * @brief Dot product of two FVec3s
     * @param[in] lhs Left-side FVec3
     * @param[in] rhs Right-side FVec3
     * @return lhs∙rhs
      }
    function FVec3_Dot(lhs:C3D_FVec; rhs:C3D_FVec):double;cdecl;external;

    {*
     * @brief Magnitude of a FVec3
     * @param[in] v Vector
     * @return ‖v‖
      }
    function FVec3_Magnitude(v:C3D_FVec):double;cdecl;external;

    {*
     * @brief Normalize a FVec3
     * @param[in] v FVec3 to normalize
     * @return v/‖v‖
      }
    function FVec3_Normalize(v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Add two FVec3s
     * @param[in] lhs Augend
     * @param[in] rhs Addend
     * @return lhs+rhs (sum)
      }
    function FVec3_Add(lhs:C3D_FVec; rhs:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Subtract two FVec3s
     * @param[in] lhs Minuend
     * @param[in] rhs Subtrahend
     * @return lhs-rhs (difference)
      }
    function FVec3_Subtract(lhs:C3D_FVec; rhs:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Distance between two 3D points
     * @param[in] lhs Relative origin
     * @param[in] rhs Relative point of interest
     * @return ‖lhs-rhs‖
      }
    function FVec3_Distance(lhs:C3D_FVec; rhs:C3D_FVec):double;cdecl;external;

    {*
     * @brief Scale a FVec3
     * @param[in] v Vector to scale
     * @param[in] s Scale factor
     * @return v*s
      }
    function FVec3_Scale(v:C3D_FVec; s:double):C3D_FVec;cdecl;external;

    {*
     * @brief Negate a FVec3
     * @note This is equivalent to `FVec3_Scale(v, -1)`
     * @param[in] v Vector to negate
     * @return -v
      }
    function FVec3_Negate(v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Cross product of two FVec3s
     * @note This returns a pseudo-vector which is perpendicular to the plane
     *       spanned by the two input vectors.
     * @param[in] lhs Left-side FVec3
     * @param[in] rhs Right-side FVec3
     * @return lhs×rhs
      }
    function FVec3_Cross(lhs:C3D_FVec; rhs:C3D_FVec):C3D_FVec;cdecl;external;

    {* @  }
    {*
     * @name Matrix Math
     * @note All matrices are 4x4 unless otherwise noted.
     * @
      }
    {*
     * @brief Zero matrix
     * @param[out] out Matrix to zero
      }
    procedure Mtx_Zeros(outPtr:PC3D_Mtx);cdecl;external;

    {*
     * @brief Copy a matrix
     * @param[out] out Output matrix
     * @param[in]  in  Input matrix
      }
    procedure Mtx_Copy(outPtr:PC3D_Mtx; inPtr:PC3D_Mtx);cdecl;external;

    {*
     * @brief Creates a matrix with the diagonal using the given parameters.
     * @param[out]  out    Output matrix.
     * @param[in]   x      The X component.
     * @param[in]   y      The Y component.
     * @param[in]   z      The Z component.
     * @param[in]   w      The W component.
      }
    procedure Mtx_Diagonal(outPtr:PC3D_Mtx; x:double; y:double; z:double; w:double);cdecl;external;

    {*
     * @brief Identity matrix
     * @param[out] out Matrix to fill
      }
    procedure Mtx_Identity(outPtr:PC3D_Mtx);cdecl;external;

    {*
     *@brief Transposes the matrix. Row => Column, and vice versa.
     *@param[in,out] out     Output matrix.
      }
    procedure Mtx_Transpose(outPtr:PC3D_Mtx);cdecl;external;

    {*
     * @brief Matrix addition
     * @param[out]   out    Output matrix.
     * @param[in]    lhs    Left matrix.
     * @param[in]    rhs    Right matrix.
     * @return lhs+rhs (sum)
      }
    procedure Mtx_Add(outPtr:PC3D_Mtx; lhs:PC3D_Mtx; rhs:PC3D_Mtx);cdecl;external;

    {*
     * @brief Matrix subtraction
     * @param[out]   out    Output matrix.
     * @param[in]    lhs    Left matrix.
     * @param[in]    rhs    Right matrix.
     * @return lhs-rhs (difference)
      }
    procedure Mtx_Subtract(outPtr:PC3D_Mtx; lhs:PC3D_Mtx; rhs:PC3D_Mtx);cdecl;external;

    {*
     * @brief Multiply two matrices
     * @param[out] out Output matrix
     * @param[in]  a   Multiplicand
     * @param[in]  b   Multiplier
      }
    procedure Mtx_Multiply(outPtr:PC3D_Mtx; a:PC3D_Mtx; b:PC3D_Mtx);cdecl;external;

    {*
     * @brief Inverse a matrix
     * @param[in,out] out Matrix to inverse
     * @retval 0.0f Degenerate matrix (no inverse)
     * @return determinant
      }
    function Mtx_Inverse(outPtr:PC3D_Mtx):double;cdecl;external;

    {*
     * @brief Multiply 3x3 matrix by a FVec3
     * @param[in] mtx Matrix
     * @param[in] v   Vector
     * @return mtx*v (product)
      }
      
    function Mtx_MultiplyFVec3(mtx:PC3D_Mtx; v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Multiply 4x4 matrix by a FVec4
     * @param[in] mtx Matrix
     * @param[in] v   Vector
     * @return mtx*v (product)
      }
      
    function Mtx_MultiplyFVec4(mtx:PC3D_Mtx; v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Multiply 4x3 matrix by a FVec3
     * @param[in] mtx Matrix
     * @param[in] v   Vector
     * @return mtx*v (product)
      }
(* Const before type ignored *)
    function Mtx_MultiplyFVecH(mtx:PC3D_Mtx; v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief Get 4x4 matrix equivalent to Quaternion
     * @param[out] m Output matrix
     * @param[in]  q Input Quaternion
      }
    procedure Mtx_FromQuat(m:PC3D_Mtx; q:C3D_FQuat);cdecl;external;

    {* @  }
    {*
     * @name 3D Transformation Matrix Math
     * @note bRightSide is used to determine which side to perform the transformation.
     *       With an input matrix A and a transformation matrix B, bRightSide being
     *       true yields AB, while being false yield BA.
     * @
      }
    {*
     * @brief 3D translation
     * @param[in,out] mtx Matrix to translate
     * @param[in]     x            X component to translate
     * @param[in]     y            Y component to translate
     * @param[in]     z            Z component to translate
     * @param[in]     bRightSide   Whether to transform from the right side
      }
    procedure Mtx_Translate(mtx:PC3D_Mtx; x:double; y:double; z:double; bRightSide:bool);cdecl;external;

    {*
     * @brief 3D Scale
     * @param[in,out] mtx Matrix to scale
     * @param[in]     x   X component to scale
     * @param[in]     y   Y component to scale
     * @param[in]     z   Z component to scale
      }
    procedure Mtx_Scale(mtx:PC3D_Mtx; x:double; y:double; z:double);cdecl;external;

    {*
     * @brief 3D Rotation
     * @param[in,out] mtx        Matrix to rotate
     * @param[in]     axis       Axis about which to rotate
     * @param[in]     angle      Radians to rotate
     * @param[in]     bRightSide Whether to transform from the right side
      }
    procedure Mtx_Rotate(mtx:PC3D_Mtx; axis:C3D_FVec; angle:double; bRightSide:bool);cdecl;external;

    {*
     * @brief 3D Rotation about the X axis
     * @param[in,out] mtx        Matrix to rotate
     * @param[in]     angle      Radians to rotate
     * @param[in]     bRightSide Whether to transform from the right side
      }
    procedure Mtx_RotateX(mtx:PC3D_Mtx; angle:double; bRightSide:bool);cdecl;external;

    {*
     * @brief 3D Rotation about the Y axis
     * @param[in,out] mtx        Matrix to rotate
     * @param[in]     angle      Radians to rotate
     * @param[in]     bRightSide Whether to transform from the right side
      }
    procedure Mtx_RotateY(mtx:PC3D_Mtx; angle:double; bRightSide:bool);cdecl;external;

    {*
     * @brief 3D Rotation about the Z axis
     * @param[in,out] mtx        Matrix to rotate
     * @param[in]     angle      Radians to rotate
     * @param[in]     bRightSide Whether to transform from the right side
      }
    procedure Mtx_RotateZ(mtx:PC3D_Mtx; angle:double; bRightSide:bool);cdecl;external;

    {* @  }
    {*
     * @name 3D Projection Matrix Math
     * @
      }
    {*
     * @brief Orthogonal projection
     * @param[out] mtx Output matrix
     * @param[in]  left         Left clip plane (X=left)
     * @param[in]  right        Right clip plane (X=right)
     * @param[in]  bottom       Bottom clip plane (Y=bottom)
     * @param[in]  top          Top clip plane (Y=top)
     * @param[in]  near         Near clip plane (Z=near)
     * @param[in]  far          Far clip plane (Z=far)
     * @param[in]  isLeftHanded Whether to build a LH projection
     * @sa Mtx_OrthoTilt
      }
    procedure Mtx_Ortho(mtx:PC3D_Mtx; left:double; right:double; bottom:double; top:double; 
                cp_near:double; cp_far:double; isLeftHanded:bool);cdecl;external;

    {*
     * @brief Perspective projection
     * @param[out] mtx          Output matrix
     * @param[in]  fovy         Vertical field of view in radians
     * @param[in]  aspect       Aspect ration of projection plane (width/height)
     * @param[in]  near         Near clip plane (Z=near)
     * @param[in]  far          Far clip plane (Z=far)
     * @param[in]  isLeftHanded Whether to build a LH projection
     * @sa Mtx_PerspTilt
     * @sa Mtx_PerspStereo
     * @sa Mtx_PerspStereoTilt
      }
    procedure Mtx_Persp(mtx:PC3D_Mtx; fovy:double; aspect:double; cp_near:double; cp_far:double; 
                isLeftHanded:bool);cdecl;external;

    {*
     * @brief Stereo perspective projection
     * @note Typically you will use iod to mean the distance between the eyes. Plug
     *       in -iod for the left eye and iod for the right eye.
     * @note The focal length is defined by screen. If objects are further than this,
     *       they will appear to be inside the screen. If objects are closer than this,
     *       they will appear to pop out of the screen. Objects at this distance appear
     *       to be at the screen.
     * @param[out] mtx          Output matrix
     * @param[in]  fovy         Vertical field of view in radians
     * @param[in]  aspect       Aspect ration of projection plane (width/height)
     * @param[in]  near         Near clip plane (Z=near)
     * @param[in]  far          Far clip plane (Z=far)
     * @param[in]  iod          Interocular distance
     * @param[in]  screen       Focal length
     * @param[in]  isLeftHanded Whether to build a LH projection
     * @sa Mtx_Persp
     * @sa Mtx_PerspTilt
     * @sa Mtx_PerspStereoTilt
      }
    procedure Mtx_PerspStereo(mtx:PC3D_Mtx; fovy:double; aspect:double; cp_near:double; cp_far:double; 
                iod:double; screen:double; isLeftHanded:bool);cdecl;external;

    {*
     * @brief Orthogonal projection, tilted to account for the 3DS screen rotation
     * @param[out] mtx          Output matrix
     * @param[in]  left         Left clip plane (X=left)
     * @param[in]  right        Right clip plane (X=right)
     * @param[in]  bottom       Bottom clip plane (Y=bottom)
     * @param[in]  top          Top clip plane (Y=top)
     * @param[in]  near         Near clip plane (Z=near)
     * @param[in]  far          Far clip plane (Z=far)
     * @param[in]  isLeftHanded Whether to build a LH projection
     * @sa Mtx_Ortho
      }
    procedure Mtx_OrthoTilt(mtx:PC3D_Mtx; left:double; right:double; bottom:double; top:double; 
                cp_near:double; cp_far:double; isLeftHanded:bool);cdecl;external;

    {*
     * @brief Perspective projection, tilted to account for the 3DS screen rotation
     * @param[out] mtx          Output matrix
     * @param[in]  fovy         Vertical field of view in radians
     * @param[in]  aspect       Aspect ration of projection plane (width/height)
     * @param[in]  near         Near clip plane (Z=near)
     * @param[in]  far          Far clip plane (Z=far)
     * @param[in]  isLeftHanded Whether to build a LH projection
     * @sa Mtx_Persp
     * @sa Mtx_PerspStereo
     * @sa Mtx_PerspStereoTilt
      }
    procedure Mtx_PerspTilt(mtx:PC3D_Mtx; fovy:double; aspect:double; cp_near:double; cp_far:double; 
                isLeftHanded:bool);cdecl;external;

    {*
     * @brief Stereo perspective projection, tilted to account for the 3DS screen rotation
     * @note See the notes for @ref Mtx_PerspStereo
     * @param[out] mtx          Output matrix
     * @param[in]  fovy         Vertical field of view in radians
     * @param[in]  aspect       Aspect ration of projection plane (width/height)
     * @param[in]  near         Near clip plane (Z=near)
     * @param[in]  far          Far clip plane (Z=far)
     * @param[in]  iod          Interocular distance
     * @param[in]  screen       Focal length
     * @param[in]  isLeftHanded Whether to build a LH projection
     * @sa Mtx_Persp
     * @sa Mtx_PerspTilt
     * @sa Mtx_PerspStereo
      }
    procedure Mtx_PerspStereoTilt(mtx:PC3D_Mtx; fovy:double; aspect:double; cp_near:double; cp_far:double; 
                iod:double; screen:double; isLeftHanded:bool);cdecl;external;

    {*
     * @brief Look-At matrix, based on DirectX implementation
     * @note See https://msdn.microsoft.com/en-us/library/windows/desktop/bb205342
     * @param[out] out            Output matrix.
     * @param[in]  cameraPosition Position of the intended camera in 3D space.
     * @param[in]  cameraTarget   Position of the intended target the camera is supposed to face in 3D space.
     * @param[in]  cameraUpVector The vector that points straight up depending on the camera's "Up" direction.
     * @param[in]  isLeftHanded   Whether to build a LH projection
      }
    procedure Mtx_LookAt(outPtr:PC3D_Mtx; cameraPosition:C3D_FVec; cameraTarget:C3D_FVec; cameraUpVector:C3D_FVec; isLeftHanded:bool);cdecl;external;

    {* @  }
    {*
     * @name Quaternion Math
     * @
      }
    {*
     * @brief Create a new Quaternion
     * @param[in] i I-component
     * @param[in] j J-component
     * @param[in] k K-component
     * @param[in] r Real component
     * @return New Quaternion
      }
    function Quat_New(i,j,k,r : double) : C3D_FVec;    

    {*
     * @brief Negate a Quaternion
     * @note This is equivalent to `Quat_Scale(v, -1)`
     * @param[in] q Quaternion to negate
     * @return -q
      }
    function Quat_Negate(q : C3D_FVec) : C3D_FVec;    

    {*
     * @brief Add two Quaternions
     * @param[in] lhs Augend
     * @param[in] rhs Addend
     * @return lhs+rhs (sum)
      }
    function Quat_Add(lhs,rhs : C3D_FVec) : C3D_FVec;    

    {*
     * @brief Subtract two Quaternions
     * @param[in] lhs Minuend
     * @param[in] rhs Subtrahend
     * @return lhs-rhs (difference)
      }
    function Quat_Subtract(lhs,rhs : C3D_FVec) : C3D_FVec;    

    {*
     * @brief Scale a Quaternion
     * @param[in] q Quaternion to scale
     * @param[in] s Scale factor
     * @return q*s
      }
    function Quat_Scale(q:C3D_FVec; s : double) : C3D_FVec;    

    {*
     * @brief Normalize a Quaternion
     * @param[in] q Quaternion to normalize
     * @return q/‖q‖
      }
    function Quat_Normalize(q : C3D_FVec) : C3D_FVec;    

    {*
     * @brief Dot product of two Quaternions
     * @param[in] lhs Left-side Quaternion
     * @param[in] rhs Right-side Quaternion
     * @return lhs∙rhs
      }
    function Quat_Dot(lhs,rhs : C3D_FVec) : double;    

    {*
     * @brief Multiply two Quaternions
     * @param[in] lhs Multiplicand
     * @param[in] rhs Multiplier
     * @return lhs*rhs
      }
    function Quat_Multiply(lhs:C3D_FQuat; rhs:C3D_FQuat):C3D_FQuat;cdecl;external;

    {*
     * @brief Raise Quaternion to a power
     * @note If p is 0, this returns the identity Quaternion.
     *       If p is 1, this returns q.
     * @param[in] q Base Quaternion
     * @param[in] p Power
     * @return q<sup>p</sup>
      }
    function Quat_Pow(q:C3D_FQuat; p:double):C3D_FQuat;cdecl;external;

    {*
     * @brief Cross product of Quaternion and FVec3
     * @param[in] q Base Quaternion
     * @param[in] v Vector to cross
     * @return q×v
      }
    function Quat_CrossFVec3(q:C3D_FQuat; v:C3D_FVec):C3D_FVec;cdecl;external;

    {*
     * @brief 3D Rotation
     * @param[in] q          Quaternion to rotate
     * @param[in] axis       Axis about which to rotate
     * @param[in] r          Radians to rotate
     * @param[in] bRightSide Whether to transform from the right side
     * @return Rotated Quaternion
      }
    function Quat_Rotate(q:C3D_FQuat; axis:C3D_FVec; r:double; bRightSide:bool):C3D_FQuat;cdecl;external;

    {*
     * @brief 3D Rotation about the X axis
     * @param[in] q          Quaternion to rotate
     * @param[in] r          Radians to rotate
     * @param[in] bRightSide Whether to transform from the right side
     * @return Rotated Quaternion
      }
    function Quat_RotateX(q:C3D_FQuat; r:double; bRightSide:bool):C3D_FQuat;cdecl;external;

    {*
     * @brief 3D Rotation about the Y axis
     * @param[in] q          Quaternion to rotate
     * @param[in] r          Radians to rotate
     * @param[in] bRightSide Whether to transform from the right side
     * @return Rotated Quaternion
      }
    function Quat_RotateY(q:C3D_FQuat; r:double; bRightSide:bool):C3D_FQuat;cdecl;external;

    {*
     * @brief 3D Rotation about the Z axis
     * @param[in] q          Quaternion to rotate
     * @param[in] r          Radians to rotate
     * @param[in] bRightSide Whether to transform from the right side
     * @return Rotated Quaternion
      }
    function Quat_RotateZ(q:C3D_FQuat; r:double; bRightSide:bool):C3D_FQuat;cdecl;external;

    {*
     * @brief Get Quaternion equivalent to 4x4 matrix
     * @note If the matrix is orthogonal or special orthogonal, where determinant(matrix) = +1.0f, then the matrix can be converted.
     * @param[in]   m Input  Matrix
     * @return      Generated Quaternion
      }
(* Const before type ignored *)
    function Quat_FromMtx(m:PC3D_Mtx):C3D_FQuat;cdecl;external;

    {*
     * @brief Identity Quaternion
     * @return Identity Quaternion
      }
    function Quat_Identity:C3D_FQuat;cdecl;external;

    {*
     * @brief Quaternion conjugate
     * @param[in] q Quaternion of which to get conjugate
     * @return q*
      }
    function Quat_Conjugate(q:C3D_FQuat):C3D_FQuat;cdecl;external;

    {*
     * @brief Quaternion inverse
     * @note This is equivalent to `Quat_Pow(v, -1)`
     * @param[in] q Quaternion of which to get inverse
     * @return q<sup>-1</sup>
      }
    function Quat_Inverse(q:C3D_FQuat):C3D_FQuat;cdecl;external;

    {*
     * @brief Cross product of FVec3 and Quaternion
     * @param[in] v Base FVec3
     * @param[in] q Quaternion to cross
     * @return v×q
      }
    function FVec3_CrossQuat(v:C3D_FVec; q:C3D_FQuat):C3D_FVec;cdecl;external;

    {*
     * @brief Converting Pitch, Yaw, and Roll to Quaternion equivalent
     * @param[in] pitch      The pitch angle in radians.
     * @param[in] yaw        The yaw angle in radians.
     * @param[in] roll       The roll angle in radians.
     * @param[in] bRightSide Whether to transform from the right side
     * @return    C3D_FQuat  The Quaternion equivalent with the pitch, yaw, and roll (in that order) orientations applied.
      }
    function Quat_FromPitchYawRoll(pitch:double; yaw:double; roll:double; bRightSide:bool):C3D_FQuat;cdecl;external;

    {*
     * @brief Quaternion Look-At
     * @param[in] source   C3D_FVec Starting position. Origin of rotation.
     * @param[in] target   C3D_FVec Target position to orient towards.
     * @param[in] forwardVector C3D_FVec The Up vector.
     * @param[in] upVector C3D_FVec The Up vector.
     * @return Quaternion rotation.
      }
    function Quat_LookAt(source:C3D_FVec; target:C3D_FVec; forwardVector:C3D_FVec; upVector:C3D_FVec):C3D_FQuat;cdecl;external;

    {*
     * @brief Quaternion, created from a given axis and angle in radians.
     * @param[in] axis  C3D_FVec The axis to rotate around at.
     * @param[in] angle float The angle to rotate. Unit: Radians
     * @return Quaternion rotation based on the axis and angle. Axis doesn't have to be orthogonal.
      }
    function Quat_FromAxisAngle(axis:C3D_FVec; angle:double):C3D_FQuat;cdecl;external;

{$endif 3dsintf}

{$ifdef 3dsimpl}

   function C3D_Angle(_angle : double) : double;
    begin
//       C3D_Angle:=_angle*M_TAU;
    end;

    function Quat_New(i,j,k,r : double) : C3D_FVec;
      begin
         Quat_New:=FVec4_New(i,j,k,r);
      end;

    function Quat_Negate(q : C3D_FVec) : C3D_FVec;
      begin
         Quat_Negate:=FVec4_Negate(q);
      end;

    function Quat_Add(lhs,rhs : C3D_FVec) : C3D_FVec;
      begin
         Quat_Add:=FVec4_Add(lhs,rhs);
      end;

    function Quat_Subtract(lhs,rhs : C3D_FVec) : C3D_FVec;
      begin
         Quat_Subtract:=FVec4_Subtract(lhs,rhs);
      end;

    function Quat_Scale(q:C3D_FVec; s : double) : C3D_FVec;
      begin
         Quat_Scale:=FVec4_Scale(q,s);
      end;

    function Quat_Normalize(q : C3D_FVec) : C3D_FVec;
      begin
         Quat_Normalize:=FVec4_Normalize(q);
      end;

    function Quat_Dot(lhs,rhs : C3D_FVec) : double;
      begin
         Quat_Dot:=FVec4_Dot(lhs,rhs);
      end;


{$endif 3dsimpl}