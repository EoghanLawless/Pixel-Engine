#include "texture.h"

namespace pixel {
	namespace graphics {

		Texture::Texture(const std::string& path) : _path(path) {
			_textureId = load();
		}

		Texture::Texture::~Texture() {}

		GLuint Texture::load() {
			BYTE* pixels = load_image(_path.c_str(), &_width, &_height);

			GLuint result;
			glGenTextures(1, &result);
			glBindTexture(GL_TEXTURE_2D, result);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

			glBindTexture(GL_TEXTURE_2D, 0);

			delete[] pixels;

			return result;
		}

		void Texture::bind() const {
			glBindTexture(GL_TEXTURE_2D, _textureId);
		}

		void Texture::unbind() const {
			glBindTexture(GL_TEXTURE_2D, 0);
		}

	}
}