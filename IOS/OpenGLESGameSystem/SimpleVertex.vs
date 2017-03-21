
//shadingを使用するflag 1の時使用する，0の時使用しない（単色にする）
uniform int u_EnableShading;
//shadingを使用しない時の色の設定（単色）
uniform vec4 u_ObjectColor;

//光源
uniform vec4 u_LightAmbient;    //光源の環境光色
uniform vec4 u_LightDiffuse;    //光源の拡散光色
uniform vec4 u_LightSpecular;   //光源の鏡面光色
uniform vec4 u_LightPos;        //光源の位置（カメラビュー座標系）

//マテリアル
uniform vec4 u_MaterialAmbient;     //マテリアルの環境光色
uniform vec4 u_MaterialDiffuse;     //マテリアルの拡散光色
uniform vec4 u_MaterialSpecular;    //マテリアルの鏡面光色
uniform float u_MaterialShininess;  //マテリアルの鏡面指数

//行列
uniform mat4 u_MMatrix;     //モデルビュー行列
uniform mat4 u_PMMatrix;    //射影行列×モデルビュー行列

//頂点情報
attribute vec4 a_Position;  //位置
attribute vec3 a_Normal;    //法線ベクトル

//出力
varying vec4 v_Color;

void main() {
    if (u_EnableShading==1) {
        //環境光の計算
        vec4 ambient=u_LightAmbient*u_MaterialAmbient;
        
        //拡散光の計算
        vec3 P=vec3(u_MMatrix*a_Position);
        vec3 L=normalize(vec3(u_LightPos)-P);  //光源方向単位ベクトル
        vec3 N=normalize(mat3(u_MMatrix)*a_Normal);  //法線単位ベクトル
        float dotLN=max(dot(L,N),0.0);
        vec4 diffuseP=vec4(dotLN);
        vec4 diffuse=diffuseP*u_LightDiffuse*u_MaterialDiffuse;
        
        //鏡面光の計算
        vec3 V=normalize(-P);  //視点方向単位ベクトル
        float dotNLEffect=ceil(dotLN);
        vec3 R=2.*dotLN*N-L;
        float specularP=pow(max(dot(R,V),0.0),u_MaterialShininess)*dotNLEffect;
        
        vec4 specular=specularP*u_LightSpecular*u_MaterialSpecular;
        //色の指定
        //v_Color=ambient+diffuse+specular;
        v_Color=ambient+specular;
    } else {
        v_Color=u_ObjectColor;
    }
    //位置の指定
    gl_Position=u_PMMatrix*a_Position;
}
