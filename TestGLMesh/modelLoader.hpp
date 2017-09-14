//
//  Model.hpp
//  TestGLMesh
//
//  Created by Arun Mudaliar on 01/09/17.
//  Copyright © 2017 Anand Mudaliar. All rights reserved.
//

#ifndef modelLoader_hpp
#define modelLoader_hpp

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <tinyfiledialogs.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

#include <mesh.hpp>
#include <loadShader.hpp>

using namespace std;

unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);

class Model
{
public:
    /*  Model Data */
    // stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    vector<Texture> textures_loaded;
    vector<Mesh>    meshes;
    string directory;
    bool gammaCorrection;
    
    /*  Functions   */
    // constructor, expects a filepath to a 3D model.
    Model(string const &path, bool gamma = false);
    
    // draws the model, and thus all its meshes
    void Draw(Shader shader);
    
private:
    /*  Functions   */
    // loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
    void loadModel(string const &path);
    
    // processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
    void processNode(aiNode *node, const aiScene *scene);
    
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};


unsigned int TextureFromFile(const char *path, const string &directory, bool gamma);

#endif /* Model_hpp */
