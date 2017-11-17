// 
// nullglu.h from Erik Wilson -- Boston University
//  This file can be used with OpenGl is not available
//
#ifndef NULLGLU_H
#define NULLGLU_H

typedef struct GLUnurbs GLUnurbs;
typedef struct GLUquadric GLUquadric;
typedef struct GLUtesselator GLUtesselator;
typedef GLUnurbs GLUnurbsObj;
typedef GLUquadric GLUquadricObj;
typedef GLUtesselator GLUtesselatorObj;
typedef GLUtesselator GLUtriangulatorObj;

#define GLU_EXT_object_space_tess          1
#define GLU_EXT_nurbs_tessellator          1
#define GLU_FALSE                          0
#define GLU_TRUE                           1
#define GLU_VERSION_1_1                    1
#define GLU_VERSION_1_2                    1
#define GLU_VERSION_1_3                    1
#define GLU_VERSION                        100800
#define GLU_EXTENSIONS                     100801
#define GLU_INVALID_ENUM                   100900
#define GLU_INVALID_VALUE                  100901
#define GLU_OUT_OF_MEMORY                  100902
#define GLU_INCOMPATIBLE_GL_VERSION        100903
#define GLU_INVALID_OPERATION              100904
#define GLU_OUTLINE_POLYGON                100240
#define GLU_OUTLINE_PATCH                  100241
#define GLU_NURBS_ERROR                    100103
#define GLU_ERROR                          100103
#define GLU_NURBS_BEGIN                    100164
#define GLU_NURBS_BEGIN_EXT                100164
#define GLU_NURBS_VERTEX                   100165
#define GLU_NURBS_VERTEX_EXT               100165
#define GLU_NURBS_NORMAL                   100166
#define GLU_NURBS_NORMAL_EXT               100166
#define GLU_NURBS_COLOR                    100167
#define GLU_NURBS_COLOR_EXT                100167
#define GLU_NURBS_TEXTURE_COORD            100168
#define GLU_NURBS_TEX_COORD_EXT            100168
#define GLU_NURBS_END                      100169
#define GLU_NURBS_END_EXT                  100169
#define GLU_NURBS_BEGIN_DATA               100170
#define GLU_NURBS_BEGIN_DATA_EXT           100170
#define GLU_NURBS_VERTEX_DATA              100171
#define GLU_NURBS_VERTEX_DATA_EXT          100171
#define GLU_NURBS_NORMAL_DATA              100172
#define GLU_NURBS_NORMAL_DATA_EXT          100172
#define GLU_NURBS_COLOR_DATA               100173
#define GLU_NURBS_COLOR_DATA_EXT           100173
#define GLU_NURBS_TEXTURE_COORD_DATA       100174
#define GLU_NURBS_TEX_COORD_DATA_EXT       100174
#define GLU_NURBS_END_DATA                 100175
#define GLU_NURBS_END_DATA_EXT             100175
#define GLU_NURBS_ERROR1                   100251
#define GLU_NURBS_ERROR2                   100252
#define GLU_NURBS_ERROR3                   100253
#define GLU_NURBS_ERROR4                   100254
#define GLU_NURBS_ERROR5                   100255
#define GLU_NURBS_ERROR6                   100256
#define GLU_NURBS_ERROR7                   100257
#define GLU_NURBS_ERROR8                   100258
#define GLU_NURBS_ERROR9                   100259
#define GLU_NURBS_ERROR10                  100260
#define GLU_NURBS_ERROR11                  100261
#define GLU_NURBS_ERROR12                  100262
#define GLU_NURBS_ERROR13                  100263
#define GLU_NURBS_ERROR14                  100264
#define GLU_NURBS_ERROR15                  100265
#define GLU_NURBS_ERROR16                  100266
#define GLU_NURBS_ERROR17                  100267
#define GLU_NURBS_ERROR18                  100268
#define GLU_NURBS_ERROR19                  100269
#define GLU_NURBS_ERROR20                  100270
#define GLU_NURBS_ERROR21                  100271
#define GLU_NURBS_ERROR22                  100272
#define GLU_NURBS_ERROR23                  100273
#define GLU_NURBS_ERROR24                  100274
#define GLU_NURBS_ERROR25                  100275
#define GLU_NURBS_ERROR26                  100276
#define GLU_NURBS_ERROR27                  100277
#define GLU_NURBS_ERROR28                  100278
#define GLU_NURBS_ERROR29                  100279
#define GLU_NURBS_ERROR30                  100280
#define GLU_NURBS_ERROR31                  100281
#define GLU_NURBS_ERROR32                  100282
#define GLU_NURBS_ERROR33                  100283
#define GLU_NURBS_ERROR34                  100284
#define GLU_NURBS_ERROR35                  100285
#define GLU_NURBS_ERROR36                  100286
#define GLU_NURBS_ERROR37                  100287
#define GLU_AUTO_LOAD_MATRIX               100200
#define GLU_CULLING                        100201
#define GLU_SAMPLING_TOLERANCE             100203
#define GLU_DISPLAY_MODE                   100204
#define GLU_PARAMETRIC_TOLERANCE           100202
#define GLU_SAMPLING_METHOD                100205
#define GLU_U_STEP                         100206
#define GLU_V_STEP                         100207
#define GLU_NURBS_MODE                     100160
#define GLU_NURBS_MODE_EXT                 100160
#define GLU_NURBS_TESSELLATOR              100161
#define GLU_NURBS_TESSELLATOR_EXT          100161
#define GLU_NURBS_RENDERER                 100162
#define GLU_NURBS_RENDERER_EXT             100162
#define GLU_OBJECT_PARAMETRIC_ERROR        100208
#define GLU_OBJECT_PARAMETRIC_ERROR_EXT    100208
#define GLU_OBJECT_PATH_LENGTH             100209
#define GLU_OBJECT_PATH_LENGTH_EXT         100209
#define GLU_PATH_LENGTH                    100215
#define GLU_PARAMETRIC_ERROR               100216
#define GLU_DOMAIN_DISTANCE                100217
#define GLU_MAP1_TRIM_2                    100210
#define GLU_MAP1_TRIM_3                    100211
#define GLU_POINT                          100010
#define GLU_LINE                           100011
#define GLU_FILL                           100012
#define GLU_SILHOUETTE                     100013
#define GLU_SMOOTH                         100000
#define GLU_FLAT                           100001
#define GLU_NONE                           100002
#define GLU_OUTSIDE                        100020
#define GLU_INSIDE                         100021
#define GLU_TESS_BEGIN                     100100
#define GLU_BEGIN                          100100
#define GLU_TESS_VERTEX                    100101
#define GLU_VERTEX                         100101
#define GLU_TESS_END                       100102
#define GLU_END                            100102
#define GLU_TESS_ERROR                     100103
#define GLU_TESS_EDGE_FLAG                 100104
#define GLU_EDGE_FLAG                      100104
#define GLU_TESS_COMBINE                   100105
#define GLU_TESS_BEGIN_DATA                100106
#define GLU_TESS_VERTEX_DATA               100107
#define GLU_TESS_END_DATA                  100108
#define GLU_TESS_ERROR_DATA                100109
#define GLU_TESS_EDGE_FLAG_DATA            100110
#define GLU_TESS_COMBINE_DATA              100111
#define GLU_CW                             100120
#define GLU_CCW                            100121
#define GLU_INTERIOR                       100122
#define GLU_EXTERIOR                       100123
#define GLU_UNKNOWN                        100124
#define GLU_TESS_WINDING_RULE              100140
#define GLU_TESS_BOUNDARY_ONLY             100141
#define GLU_TESS_TOLERANCE                 100142
#define GLU_TESS_ERROR1                    100151
#define GLU_TESS_ERROR2                    100152
#define GLU_TESS_ERROR3                    100153
#define GLU_TESS_ERROR4                    100154
#define GLU_TESS_ERROR5                    100155
#define GLU_TESS_ERROR6                    100156
#define GLU_TESS_ERROR7                    100157
#define GLU_TESS_ERROR8                    100158
#define GLU_TESS_MISSING_BEGIN_POLYGON     100151
#define GLU_TESS_MISSING_BEGIN_CONTOUR     100152
#define GLU_TESS_MISSING_END_POLYGON       100153
#define GLU_TESS_MISSING_END_CONTOUR       100154
#define GLU_TESS_COORD_TOO_LARGE           100155
#define GLU_TESS_NEED_COMBINE_CALLBACK     100156
#define GLU_TESS_WINDING_ODD               100130
#define GLU_TESS_WINDING_NONZERO           100131
#define GLU_TESS_WINDING_POSITIVE          100132
#define GLU_TESS_WINDING_NEGATIVE          100133
#define GLU_TESS_WINDING_ABS_GEQ_TWO       100134
#define GLU_TESS_MAX_COORD 1.0e150

inline void gluBeginCurve (GLUnurbs* nurb){};
inline void gluBeginPolygon (GLUtesselator* tess){};
inline void gluBeginSurface (GLUnurbs* nurb){};
inline void gluBeginTrim (GLUnurbs* nurb){};
inline GLint gluBuild1DMipmapLevels (GLenum target, ... ){};
inline GLint gluBuild1DMipmaps (GLenum target, ... ){};
inline GLint gluBuild2DMipmapLevels (GLenum target, ... ){};
inline GLint gluBuild2DMipmaps (GLenum target, ... ){};
inline GLint gluBuild3DMipmapLevels (GLenum target, ... ){};
inline GLint gluBuild3DMipmaps (GLenum target, ... ){};
inline GLboolean gluCheckExtension (const GLubyte *extName, ... ){};
inline void gluCylinder (GLUquadric* quad, ... ){};
inline void gluDeleteNurbsRenderer (GLUnurbs* nurb){};
inline void gluDeleteQuadric (GLUquadric* quad){};
inline void gluDeleteTess (GLUtesselator* tess){};
inline void gluDisk (GLUquadric* quad, ... ){};
inline void gluEndCurve (GLUnurbs* nurb){};
inline void gluEndPolygon (GLUtesselator* tess){};
inline void gluEndSurface (GLUnurbs* nurb){};
inline void gluEndTrim (GLUnurbs* nurb){};
inline const GLubyte * gluErrorString (GLenum error){};
inline void gluGetNurbsProperty (GLUnurbs* nurb, ... ){};
inline const GLubyte * gluGetString (GLenum name){};
inline void gluGetTessProperty (GLUtesselator* tess, ... ){};
inline void gluLoadSamplingMatrices (GLUnurbs* nurb, ... ){};
inline void gluLookAt (GLdouble eyeX, ... ){};
inline GLUnurbs* gluNewNurbsRenderer (void){};
inline GLUquadric* gluNewQuadric (void){};
inline GLUtesselator* gluNewTess (void){};
inline void gluNextContour (GLUtesselator* tess, ... ){};
inline void gluNurbsCallback (GLUnurbs* nurb, ... ){};
inline void gluNurbsCallbackData (GLUnurbs* nurb, ... ){};
inline void gluNurbsCallbackDataEXT (GLUnurbs* nurb, ... ){};
inline void gluNurbsCurve (GLUnurbs* nurb, ... ){};
inline void gluNurbsProperty (GLUnurbs* nurb, ... ){};
inline void gluNurbsSurface (GLUnurbs* nurb, ... ){};
inline void gluOrtho2D (GLdouble left, ... ){};
inline void gluPartialDisk (GLUquadric* quad, ... ){};
inline void gluPerspective (GLdouble fovy, ... ){};
inline void gluPickMatrix (GLdouble x, ... ){};
inline GLint gluProject (GLdouble objX, ... ){};
inline void gluPwlCurve (GLUnurbs* nurb, ... ){};
inline void gluQuadricCallback (GLUquadric* quad, ... ){};
inline void gluQuadricDrawStyle (GLUquadric* quad, ... ){};
inline void gluQuadricNormals (GLUquadric* quad, ... ){};
inline void gluQuadricOrientation (GLUquadric* quad, ... ){};
inline void gluQuadricTexture (GLUquadric* quad, ... ){};
inline GLint gluScaleImage (GLenum format, ... ){};
inline void gluSphere (GLUquadric* quad, ... ){};
inline void gluTessBeginContour (GLUtesselator* tess){};
inline void gluTessBeginPolygon (GLUtesselator* tess, ... ){};
inline void gluTessCallback (GLUtesselator* tess, ... ){};
inline void gluTessEndContour (GLUtesselator* tess){};
inline void gluTessEndPolygon (GLUtesselator* tess){};
inline void gluTessNormal (GLUtesselator* tess, ... ){};
inline void gluTessProperty (GLUtesselator* tess, ... ){};
inline void gluTessVertex (GLUtesselator* tess, ... ){};
inline GLint gluUnProject (GLdouble winX, ... ){};
inline GLint gluUnProject4 (GLdouble winX, ... ){};

#endif // NULLGLU_H
