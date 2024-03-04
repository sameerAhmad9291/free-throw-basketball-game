#include <windows.h>								// Header File For Windows												
#include <gl\glu.h>									// Header File For The GLu32 Library
#include <olectl.h>									// Header File For The OLE Controls Library	(Used In BuildTexture)
#include <math.h>	
#include <glut.h>



class Texture
{

	public:

		GLuint	textures[10];		

		int Texture:: BuildTexture(char *szPathName, GLuint &texid);

		bool Texture:: Initialize (void);
	
};

