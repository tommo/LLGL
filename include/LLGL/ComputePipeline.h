/*
 * ComputePipeline.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_COMPUTE_PIPELINE_H__
#define __LLGL_COMPUTE_PIPELINE_H__


#include "Export.h"


namespace LLGL
{


class ShaderProgram;

//! Compute pipeline descriptor structure.
struct ComputePipelineDescriptor
{
    /**
    \brief Pointer to the shader program for the compute pipeline.
    \remarks This must never be null when "RenderSystem::CreateComputePipeline" is called with this structure.
    \see RenderSystem::CreateComputePipeline
    \see RenderSystem::CreateShaderProgram
    */
    ShaderProgram* shaderProgram   = nullptr;
};


//! Compute pipeline interface.
class LLGL_EXPORT ComputePipeline
{

    public:

        virtual ~ComputePipeline()
        {
        }

};


} // /namespace LLGL


#endif



// ================================================================================
