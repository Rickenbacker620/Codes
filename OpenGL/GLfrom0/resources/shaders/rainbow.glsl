#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
out vec4 bPos;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    bPos = vec4(aPos,1.0);
}

#shader fragment
#version 330 core
uniform float time;
uniform vec2 resolution;

in vec4 bPos;

void main( void ) {
    vec2 mouse = vec2(0.0,0.0);
    vec2 resolution = vec2(800.0,600.0);
	vec2 position = ( gl_FragColor.xy / resolution.xy ) + mouse / 4.0;

	float color = 0.0;
	color += sin( position.x * cos( time / 15.0 ) * 80.0 ) + cos( position.y * cos( time / 15.0 ) * 10.0 );
	color += sin( position.y * sin( time / 10.0 ) * 40.0 ) + cos( position.x * sin( time / 25.0 ) * 40.0 );
	color += sin( position.x * sin( time / 5.0 ) * 10.0 ) + sin( position.y * sin( time / 35.0 ) * 80.0 );
	color *= sin( time / 10.0 ) * 0.5;

	gl_FragColor = vec4( vec3( color, color * 0.5, sin( color + time / 3.0 ) * 0.75 ), 1.0 );


}