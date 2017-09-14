//
//  meshLoader.hpp
//  TestGLMesh
//
//  Created by Arun Mudaliar on 01/09/17.
//  Copyright © 2017 Anand Mudaliar. All rights reserved.
//

#ifndef mesh_hpp
#define mesh_hpp

#include <glad/glad.h> // holds all OpenGL type declarations
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include <loadshader.hpp>

using namespace std;

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    string type;
    aiString path;
};

class Mesh {
public:
    /*  Mesh Data  */
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;
    
    /*  Functions  */
    // constructor
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    // render the mesh
    void Draw(Shader shader);

    
private:
    unsigned int VBO, EBO;
    void setupMesh();
    };


#endif /* meshLoader_hpp */
