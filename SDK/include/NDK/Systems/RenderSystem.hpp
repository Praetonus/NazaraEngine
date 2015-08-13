// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Development Kit"
// For conditions of distribution and use, see copyright notice in Prerequesites.hpp

#pragma once

#ifndef NDK_SYSTEMS_RENDERSYSTEM_HPP
#define NDK_SYSTEMS_RENDERSYSTEM_HPP

#include <Nazara/Graphics/AbstractBackground.hpp>
#include <Nazara/Graphics/DepthRenderTechnique.hpp>
#include <Nazara/Graphics/ForwardRenderTechnique.hpp>
#include <Nazara/Renderer/RenderTexture.hpp>
#include <NDK/EntityList.hpp>
#include <NDK/System.hpp>
#include <unordered_map>
#include <vector>

namespace Ndk
{
	class GraphicsComponent;

	class NDK_API RenderSystem : public System<RenderSystem>
	{
		public:
			RenderSystem();
			inline RenderSystem(const RenderSystem& renderSystem);
			~RenderSystem() = default;

			inline const NzBackgroundRef& GetDefaultBackground() const;

			inline void SetDefaultBackground(NzBackgroundRef background);

			static SystemIndex systemIndex;

		private:
			void OnEntityRemoved(Entity* entity) override;
			void OnEntityValidation(Entity* entity, bool justAdded) override;
			void OnUpdate(float elapsedTime) override;
			void UpdateDirectionalShadowMaps(const NzAbstractViewer& viewer);
			void UpdatePointSpotShadowMaps();

			EntityList m_cameras;
			EntityList m_drawables;
			EntityList m_directionalLights;
			EntityList m_lights;
			EntityList m_pointSpotLights;
			NzBackgroundRef m_background;
			NzDepthRenderTechnique m_shadowTechnique;
			NzForwardRenderTechnique m_renderTechnique;
			NzRenderTexture m_shadowRT;
	};
}

#include <NDK/Systems/RenderSystem.inl>

#endif // NDK_SYSTEMS_RENDERSYSTEM_HPP
