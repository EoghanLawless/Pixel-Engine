#include "group.h"

namespace pixel {
	namespace graphics {
		Group::Group(const maths::mat4& matrix) : _transformationMatrix(matrix) {}

		void Group::add(Renderable2D* renderable) {
			_renderables.push_back(renderable);
		}

		void Group::submit(Renderer2D* renderer) const {
			renderer->push(_transformationMatrix);

			for (const Renderable2D* renderable : _renderables)
				renderable->submit(renderer);

			renderer->pop();
		}
	}
}