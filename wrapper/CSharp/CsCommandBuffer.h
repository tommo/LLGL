/*
 * CsCommandBuffer.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2019 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#pragma once

#include <vcclr.h>
#include <LLGL/CommandBuffer.h>
#include "CsTypes.h"
#include "CsRenderSystemChild.h"
#include "CsCommandBufferFlags.h"
#include "CsPipelineStateFlags.h"
#include "CsRenderTarget.h"
#include "CsColor.h"

#using <System.dll>
#using <System.Core.dll>
#using <System.Runtime.InteropServices.dll>


using namespace System;
using namespace System::Runtime::InteropServices;


namespace SharpLLGL
{


public ref class CommandBuffer
{

    internal:

        property LLGL::CommandBuffer* Native
        {
            LLGL::CommandBuffer* get();
        }

    public:

        /* ----- Common ----- */

        CommandBuffer(LLGL::CommandBuffer* native);

        /* ----- Encoding ----- */

        void Begin();
        void End();

        generic <typename T>
        void UpdateBuffer(Buffer^ dstBuffer, System::UInt64 dstOffset, array<T>^ data);

        void CopyBuffer(Buffer^ dstBuffer, System::UInt64 dstOffset, Buffer^ srcBuffer, System::UInt64 srcOffset, System::UInt64 size);

        /* ----- Configuration ----- */

        #if 0
        void SetGraphicsAPIDependentState(APIDependentStateDescriptor stateDesc);
        #endif

        /* ----- Viewport and Scissor ----- */

        void SetViewport(Viewport^ viewport);
        void SetViewports(array<Viewport^>^ viewports);

        void SetScissor(Scissor^ scissor);
        void SetScissors(array<Scissor^>^ scissors);

        /* ----- Clear ----- */

        void SetClearColor(ColorRGBA<float>^ color);
        void SetClearColor(float r, float g, float b, float a);
        void SetClearDepth(float depth);
        void SetClearStencil(unsigned int stencil);

        void Clear(ClearFlags flags);

        void ClearAttachments(array<AttachmentClear^>^ attachments);

        /* ----- Input Assembly ------ */

        void SetVertexBuffer(Buffer^ buffer);
        void SetVertexBufferArray(BufferArray^ bufferArray);
        void SetIndexBuffer(Buffer^ buffer);

        /* ----- Resource Heaps ----- */

        void SetGraphicsResourceHeap(ResourceHeap^ resourceHeap);
        void SetGraphicsResourceHeap(ResourceHeap^ resourceHeap, unsigned int firstSet);

        void SetComputeResourceHeap(ResourceHeap^ resourceHeap);
        void SetComputeResourceHeap(ResourceHeap^ resourceHeap, unsigned int firstSet);

        /* ----- Render Passes ----- */

        void BeginRenderPass(RenderTarget^ renderTarget);
        void BeginRenderPass(RenderTarget^ renderTarget, RenderPass^ renderPass);
        void BeginRenderPass(RenderTarget^ renderTarget, RenderPass^ renderPass, array<ClearValue^>^ clearValues);

        void EndRenderPass();

        /* ----- Pipeline States ----- */

        void SetPipelineState(PipelineState^ pipelineState);
        void SetBlendFactor(ColorRGBA<float>^ color);
        void SetStencilReference(unsigned int reference);
        //void SetStencilReference(unsigned int reference, const StencilFace stencilFace);

        #if 0
        void SetUniform(UniformLocation location, const void* data, std::uint32_t dataSize);
        void SetUniforms(UniformLocation location, std::uint32_t count, const void* data, std::uint32_t dataSize);
        #endif

        /* ----- Queries ----- */

        #if 0
        void BeginQuery(QueryHeap^ queryHeap);
        void BeginQuery(QueryHeap^ queryHeap, unsigned int query);
        void EndQuery(QueryHeap^ queryHeap);

        void BeginRenderCondition(QueryHeap^ queryHeap);
        void BeginRenderCondition(QueryHeap^ queryHeap, unsigned int query);
        void BeginRenderCondition(QueryHeap^ queryHeap, unsigned int query, RenderConditionMode mode);
        void EndRenderCondition();
        #endif

        /* ----- Stream Outputs ------ */

        void BeginStreamOutput(array<Buffer^>^ buffers);
        void EndStreamOutput();

        /* ----- Drawing ----- */

        void Draw(unsigned int numVertices, unsigned int firstVertex);
        void DrawIndexed(unsigned int numIndices, unsigned int firstIndex);
        void DrawIndexed(unsigned int numIndices, unsigned int firstIndex, int vertexOffset);
        void DrawInstanced(unsigned int numVertices, unsigned int firstVertex, unsigned int numInstances);
        void DrawInstanced(unsigned int numVertices, unsigned int firstVertex, unsigned int numInstances, unsigned int firstInstance);
        void DrawIndexedInstanced(unsigned int numIndices, unsigned int numInstances, unsigned int firstIndex);
        void DrawIndexedInstanced(unsigned int numIndices, unsigned int numInstances, unsigned int firstIndex, int vertexOffset);
        void DrawIndexedInstanced(unsigned int numIndices, unsigned int numInstances, unsigned int firstIndex, int vertexOffset, unsigned int firstInstance);

        /* ----- Compute ----- */

        void Dispatch(unsigned int groupSizeX, unsigned int groupSizeY, unsigned int groupSizeZ);

    private:

        LLGL::CommandBuffer* native_ = nullptr;

};


} // /namespace SharpLLGL



// ================================================================================
