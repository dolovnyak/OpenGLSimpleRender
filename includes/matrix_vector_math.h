/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector_math.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:08:27 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:09:16 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_VECTOR_MATH_H
# define MATRIX_VECTOR_MATH_H

# include "math.h"
# include "libft.h"
# include <GL/glew.h>

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

typedef struct	s_mat1x4
{
	float		a1;
	float		a2;
	float		a3;
	float		a4;
}				t_mat1x4;

typedef struct	s_mat4
{
	t_vec4		v1;
	t_vec4		v2;
	t_vec4		v3;
	t_vec4		v4;
}				t_mat4;

t_mat4			mvm_x_rotate(t_mat4 transform, float angle);
t_mat4			mvm_y_rotate(t_mat4 transform, float angle);
t_mat4			mvm_z_rotate(t_mat4 transform, float angle);

t_mat4			mvm_translate(t_mat4 transform, t_vec3 vec);

t_mat4			mvm_scale(t_mat4 transform, t_vec3 vec);

t_mat4			mvm_perspective(float fov_y, float aspect,
		float near_z, float far_z);

t_mat4			mvm_multiply_m4_m4(t_mat4 m1, t_mat4 m2);
float			mvm_multiply_m1x4_v4(t_mat1x4 m, t_vec4 v);
t_vec3			mvm_multiply_v3_f(t_vec3 vec, float n);

t_vec3			mvm_add_v3_v3(t_vec3 vec1, t_vec3 vec2);

t_mat4			mvm_identity_m4x4();

t_mat1x4		mvm_get_m4_row(t_mat4 m, int row);

float			mvm_to_radians(float angle);

#endif
