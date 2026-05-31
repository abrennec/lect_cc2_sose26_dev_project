// Ball.h

/* #pragma once should always be at the top of your header files
 * it prevents other headers like "ofMain.h" from being included more than once in your app
 * (note that ofMain.h is also included in ofApp.h)
 */

#pragma once		
#include "ofMain.h"		// ofMain.h lets our Ball "see" openFrameworks

class Arrow {

public:		// other classes can access the following functions & variables:

	Arrow();				// "constructor" function - required for every class
						// this is automatically called whenever we create a new ball

	void update();
	void draw();
    
    ofColor color;
    
private:
    glm::vec3 start;
    glm::vec3 end;
    float arrowSize;
    
    float x = 0;
    float y = 0;
    float mouseY = 0;
    float mouseX = 0;
};
