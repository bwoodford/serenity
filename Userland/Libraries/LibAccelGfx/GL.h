/*
 * Copyright (c) 2023, Aliaksandr Kalenik <kalenik.aliaksandr@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Vector.h>
#include <GL/gl.h>
#include <LibGfx/Forward.h>

namespace AccelGfx::GL {

enum class ShaderType {
    Vertex,
    Fragment,
};

struct Shader {
    GLuint id;
};

struct Program {
    GLuint id;
};

struct VertexAttribute {
    GLint id;
};

struct Uniform {
    GLint id;
};

struct Texture {
    GLuint id;
};

void set_viewport(Gfx::IntRect);
void enable_blending();

void read_pixels(Gfx::IntRect, Gfx::Bitmap&);

Shader create_shader(ShaderType type, char const* source);
Program create_program(Shader const& vertex_shader, Shader const& fragment_shader);
void use_program(Program const&);
VertexAttribute get_attribute_location(Program const&, char const* name);
Uniform get_uniform_location(Program const&, char const* name);
void delete_program(Program const&);

Texture create_texture();
void bind_texture(Texture const&);
void upload_texture_data(Texture const& texture, Gfx::Bitmap const& bitmap);
void delete_texture(Texture const&);

void set_uniform(Uniform const& uniform, float, float, float, float);
void set_vertex_attribute(VertexAttribute const& attribute, Span<float> values, int number_of_components);

enum class ScalingMode {
    Nearest,
    Linear,
};
void set_texture_scale_mode(ScalingMode);

void clear_color(Gfx::Color const&);

enum class DrawPrimitive {
    Triangles,
    TriangleFan,
};

void draw_arrays(DrawPrimitive, size_t count);

}
