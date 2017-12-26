
#version 120

//uniform sampler2DRect tex0;     // ソースのテクスチャ
uniform float mindistance;      // 閾値
uniform float maxdistance;      // 閾値

uniform  sampler2DRect depth;    // キーの色
varying vec2 texCoordVarying;

void main()
{
    // テクスチャーの色を取得
    //vec4 texel0 = texture2DRect(tex0, texCoordVarying);
    // キーの色との差分を計算
    //float diff = length(chromaKeyColor - texel0.rgb);
    if(mindistance < depth && depth < maxdistance){
        
       gl_FragColor = vec4(0,0,0,255);
    }else{
      
        gl_FragColor = vec4(255,0,0,255);
    }
}
