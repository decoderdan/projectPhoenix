  


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>projectChimaera/Drivers/vNavIMU/include/vNavIMU/vncp_services.h at master · alexsleat/projectChimaera</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <link rel="logo" type="image/svg" href="http://github-media-downloads.s3.amazonaws.com/github-logo.svg" />
    <link rel="xhr-socket" href="/_sockets" />


    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="github" name="octolytics-app-id" /><meta content="4387844" name="octolytics-actor-id" /><meta content="6724fef95ca66b1721a48fc3380a0f98824bd983c9188c66585a304e1c2c3abb" name="octolytics-actor-hash" />

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="E/J5yMbdx1u/0AjbIXscdtgDWlF6wTc5JrXKQJCYF2M=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/assets/github-fdebe8d3f60746fb87c763a59741ff520ae3d8e8.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://a248.e.akamai.net/assets.github.com/assets/github2-d530e63e2c132c7f0e6ac7228e7e1ab9ef2a8d94.css" media="all" rel="stylesheet" type="text/css" />
    


      <script src="https://a248.e.akamai.net/assets.github.com/assets/frameworks-92d138f450f2960501e28397a2f63b0f100590f0.js" type="text/javascript"></script>
      <script src="https://a248.e.akamai.net/assets.github.com/assets/github-4037f12703c2d563310be4fcd52a229189468cce.js" type="text/javascript"></script>
      
      <meta http-equiv="x-pjax-version" content="80973bfd2a5cb09c53d745b26b5b1dc0">

        <link data-pjax-transient rel='permalink' href='/alexsleat/projectChimaera/blob/636edcda74a3a158bf88efae8b7814645184a1b3/Drivers/vNavIMU/include/vNavIMU/vncp_services.h'>
    <meta property="og:title" content="projectChimaera"/>
    <meta property="og:type" content="githubog:gitrepository"/>
    <meta property="og:url" content="https://github.com/alexsleat/projectChimaera"/>
    <meta property="og:image" content="https://secure.gravatar.com/avatar/927d325c2b7f43176703521bcf18ea60?s=420&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png"/>
    <meta property="og:site_name" content="GitHub"/>
    <meta property="og:description" content="projectChimaera - Rinzler is an exceptionally skilled warrior and is the elite combatant in all games in the Grid."/>
    <meta property="twitter:card" content="summary"/>
    <meta property="twitter:site" content="@GitHub">
    <meta property="twitter:title" content="alexsleat/projectChimaera"/>

    <meta name="description" content="projectChimaera - Rinzler is an exceptionally skilled warrior and is the elite combatant in all games in the Grid." />


    <meta content="305784" name="octolytics-dimension-user_id" /><meta content="2822251" name="octolytics-dimension-repository_id" />
  <link href="https://github.com/alexsleat/projectChimaera/commits/master.atom" rel="alternate" title="Recent Commits to projectChimaera:master" type="application/atom+xml" />

  </head>


  <body class="logged_in page-blob linux vis-public fork env-production  ">
    <div id="wrapper">

      

      
      
      

      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/">
  <span class="mega-icon mega-icon-invertocat"></span>
</a>

    <div class="divider-vertical"></div>

      <a href="/notifications" class="notification-indicator tooltipped downwards" title="You have no unread notifications">
    <span class="mail-status all-read"></span>
  </a>
  <div class="divider-vertical"></div>


      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">
  <a href="/search/advanced" class="advanced-search-icon tooltipped downwards command-bar-search" id="advanced_search" title="Advanced search"><span class="mini-icon mini-icon-advanced-search "></span></a>

  <input type="text" data-hotkey="/ s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    data-username="matthuxford"
      data-repo="alexsleat/projectChimaera"
      data-branch="master"
      data-sha="fb648041dc514e860e9140c35e4957488ffdfd31"
  >

    <input type="hidden" name="nwo" value="alexsleat/projectChimaera" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item selected">
            <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item">
            <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="mini-icon help tooltipped downwards" title="Show command bar help">
    <span class="mini-icon mini-icon-help"></span>
  </span>

    <input type="hidden" name="type" value="Code" />

  <input type="hidden" name="ref" value="cmdform">

  <div class="divider-vertical"></div>

</form>
        <ul class="top-nav">
            <li class="explore"><a href="https://github.com/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="http://help.github.com">Help</a></li>
        </ul>
      </div>

    

  

    <ul id="user-links">
      <li>
        <a href="https://github.com/matthuxford" class="name">
          <img height="20" src="https://secure.gravatar.com/avatar/159652c8fcc2a050d13498a7c3af0bba?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png" width="20" /> matthuxford
        </a>
      </li>

        <li>
          <a href="/new" id="new_repo" class="tooltipped downwards" title="Create a new repo">
            <span class="mini-icon mini-icon-create"></span>
          </a>
        </li>

        <li>
          <a href="/settings/profile" id="account_settings"
            class="tooltipped downwards"
            title="Account settings ">
            <span class="mini-icon mini-icon-account-settings"></span>
          </a>
        </li>
        <li>
          <a class="tooltipped downwards" href="/logout" data-method="post" id="logout" title="Sign out">
            <span class="mini-icon mini-icon-logout"></span>
          </a>
        </li>

    </ul>


<div class="js-new-dropdown-contents hidden">
  <ul class="dropdown-menu">
    <li>
      <a href="/new"><span class="mini-icon mini-icon-create"></span> New repository</a>
    </li>
    <li>
        <a href="https://github.com/alexsleat/projectChimaera/issues/new"><span class="mini-icon mini-icon-issue-opened"></span> New issue</a>
    </li>
    <li>
    </li>
    <li>
      <a href="/organizations/new"><span class="mini-icon mini-icon-u-list"></span> New organization</a>
    </li>
  </ul>
</div>


    
  </div>
</div>

      

      

      


            <div class="site hfeed" itemscope itemtype="http://schema.org/WebPage">
      <div class="hentry">
        
        <div class="pagehead repohead instapaper_ignore readability-menu ">
          <div class="container">
            <div class="title-actions-bar">
              

<ul class="pagehead-actions">


    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="E/J5yMbdx1u/0AjbIXscdtgDWlF6wTc5JrXKQJCYF2M=" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="2822251" />

    <div class="select-menu js-menu-container js-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">
          <span class="mini-icon mini-icon-watching"></span>
          Watch
        </span>
      </span>

      <div class="select-menu-modal-holder js-menu-content">
        <div class="select-menu-modal">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container">

            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for discussions in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-watching"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

    <li class="js-toggler-container js-social-container starring-container ">
      <a href="/alexsleat/projectChimaera/unstar" class="minibutton js-toggler-target star-button starred upwards" title="Unstar this repo" data-remote="true" data-method="post" rel="nofollow">
        <span class="mini-icon mini-icon-remove-star"></span>
        <span class="text">Unstar</span>
      </a>
      <a href="/alexsleat/projectChimaera/star" class="minibutton js-toggler-target star-button unstarred upwards" title="Star this repo" data-remote="true" data-method="post" rel="nofollow">
        <span class="mini-icon mini-icon-star"></span>
        <span class="text">Star</span>
      </a>
      <a class="social-count js-social-count" href="/alexsleat/projectChimaera/stargazers">5</a>
    </li>

        <li>
          <a href="/alexsleat/projectChimaera/fork" class="minibutton js-toggler-target fork-button lighter upwards" title="Fork this repo" rel="nofollow" data-method="post">
            <span class="mini-icon mini-icon-branch-create"></span>
            <span class="text">Fork</span>
          </a>
          <a href="/alexsleat/projectChimaera/network" class="social-count">1</a>
        </li>


</ul>

              <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
                <span class="repo-label"><span>public</span></span>
                <span class="mega-icon mega-icon-repo-forked"></span>
                <span class="author vcard">
                  <a href="/alexsleat" class="url fn" itemprop="url" rel="author">
                  <span itemprop="title">alexsleat</span>
                  </a></span> /
                <strong><a href="/alexsleat/projectChimaera" class="js-current-repository">projectChimaera</a></strong>
                  <span class="fork-flag">
                    <span class="text">forked from <a href="/GarethG/ProjectRinzler">GarethG/ProjectRinzler</a></span>
                  </span>
              </h1>
            </div>

            
  <ul class="tabs">
    <li class="pulse-nav"><a href="/alexsleat/projectChimaera/pulse" class="js-selected-navigation-item " data-selected-links="pulse /alexsleat/projectChimaera/pulse" rel="nofollow"><span class="mini-icon mini-icon-pulse"></span></a></li>
    <li><a href="/alexsleat/projectChimaera" class="js-selected-navigation-item selected" data-selected-links="repo_source repo_downloads repo_commits repo_tags repo_branches /alexsleat/projectChimaera">Code</a></li>
    <li><a href="/alexsleat/projectChimaera/network" class="js-selected-navigation-item " data-selected-links="repo_network /alexsleat/projectChimaera/network">Network</a></li>
    <li><a href="/alexsleat/projectChimaera/pulls" class="js-selected-navigation-item " data-selected-links="repo_pulls /alexsleat/projectChimaera/pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/alexsleat/projectChimaera/issues" class="js-selected-navigation-item " data-selected-links="repo_issues /alexsleat/projectChimaera/issues">Issues <span class='counter'>10</span></a></li>

      <li><a href="/alexsleat/projectChimaera/wiki" class="js-selected-navigation-item " data-selected-links="repo_wiki /alexsleat/projectChimaera/wiki">Wiki</a></li>


    <li><a href="/alexsleat/projectChimaera/graphs" class="js-selected-navigation-item " data-selected-links="repo_graphs repo_contributors /alexsleat/projectChimaera/graphs">Graphs</a></li>


  </ul>
  
<div class="tabnav">

  <span class="tabnav-right">
    <ul class="tabnav-tabs">
          <li><a href="/alexsleat/projectChimaera/tags" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_tags /alexsleat/projectChimaera/tags">Tags <span class="counter blank">0</span></a></li>
    </ul>
  </span>

  <div class="tabnav-widget scope">


    <div class="select-menu js-menu-container js-select-menu js-branch-menu">
      <a class="minibutton select-menu-button js-menu-target" data-hotkey="w" data-ref="master">
        <span class="mini-icon mini-icon-branch"></span>
        <i>branch:</i>
        <span class="js-select-button">master</span>
      </a>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">

        <div class="select-menu-modal">
          <div class="select-menu-header">
            <span class="select-menu-title">Switch branches/tags</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-filters">
            <div class="select-menu-text-filter">
              <input type="text" id="commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
            </div>
            <div class="select-menu-tabs">
              <ul>
                <li class="select-menu-tab">
                  <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
                </li>
                <li class="select-menu-tab">
                  <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
                </li>
              </ul>
            </div><!-- /.select-menu-tabs -->
          </div><!-- /.select-menu-filters -->

          <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket css-truncate" data-tab-filter="branches">

            <div data-filterable-for="commitish-filter-field" data-filterable-type="substring">

                <div class="select-menu-item js-navigation-item selected">
                  <span class="select-menu-item-icon mini-icon mini-icon-confirm"></span>
                  <a href="/alexsleat/projectChimaera/blob/master/Drivers/vNavIMU/include/vNavIMU/vncp_services.h" class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target" data-name="master" rel="nofollow" title="master">master</a>
                </div> <!-- /.select-menu-item -->
            </div>

              <div class="select-menu-no-results">Nothing to show</div>
          </div> <!-- /.select-menu-list -->


          <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket css-truncate" data-tab-filter="tags">
            <div data-filterable-for="commitish-filter-field" data-filterable-type="substring">

            </div>

            <div class="select-menu-no-results">Nothing to show</div>

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

  </div> <!-- /.scope -->

  <ul class="tabnav-tabs">
    <li><a href="/alexsleat/projectChimaera" class="selected js-selected-navigation-item tabnav-tab" data-selected-links="repo_source /alexsleat/projectChimaera">Files</a></li>
    <li><a href="/alexsleat/projectChimaera/commits/master" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_commits /alexsleat/projectChimaera/commits/master">Commits</a></li>
    <li><a href="/alexsleat/projectChimaera/branches" class="js-selected-navigation-item tabnav-tab" data-selected-links="repo_branches /alexsleat/projectChimaera/branches" rel="nofollow">Branches <span class="counter ">1</span></a></li>
  </ul>

</div>

  
  
  


            
          </div>
        </div><!-- /.repohead -->

        <div id="js-repo-pjax-container" class="container context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:e604b59031a9e481226870ed7f7570ba -->
<!-- blob contrib frag key: views10/v8/blob_contributors:v21:e604b59031a9e481226870ed7f7570ba -->


<div id="slider">
    <div class="frame-meta">

      <p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

        <div class="breadcrumb">
          <span class='bold'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">projectChimaera</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">Drivers</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">vNavIMU</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU/include" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">include</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/alexsleat/projectChimaera/tree/master/Drivers/vNavIMU/include/vNavIMU" class="js-slide-to" data-branch="master" data-direction="back" itemscope="url"><span itemprop="title">vNavIMU</span></a></span><span class="separator"> / </span><strong class="final-path">vncp_services.h</strong> <span class="js-zeroclipboard zeroclipboard-button" data-clipboard-text="Drivers/vNavIMU/include/vNavIMU/vncp_services.h" data-copied-hint="copied!" title="copy to clipboard"><span class="mini-icon mini-icon-clipboard"></span></span>
        </div>

      <a href="/alexsleat/projectChimaera/find/master" class="js-slide-to" data-hotkey="t" style="display:none">Show File Finder</a>


        <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/alexsleat/projectChimaera/contributors/master/Drivers/vNavIMU/include/vNavIMU/vncp_services.h">
          Fetching contributors…

          <div class="participation">
            <p class="loader-loading"><img alt="Octocat-spinner-32-eaf2f5" height="16" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-32-EAF2F5.gif?1340659511" width="16" /></p>
            <p class="loader-error">Cannot retrieve contributors at this time</p>
          </div>
        </div>

    </div><!-- ./.frame-meta -->

    <div class="frames">
      <div class="frame" data-permalink-url="/alexsleat/projectChimaera/blob/636edcda74a3a158bf88efae8b7814645184a1b3/Drivers/vNavIMU/include/vNavIMU/vncp_services.h" data-title="projectChimaera/Drivers/vNavIMU/include/vNavIMU/vncp_services.h at master · alexsleat/projectChimaera · GitHub" data-type="blob">

        <div id="files" class="bubble">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><b class="mini-icon mini-icon-text-file"></b></span>
                <span class="mode" title="File Mode">file</span>
                  <span>194 lines (170 sloc)</span>
                <span>6.725 kb</span>
              </div>
              <div class="actions">
                <div class="button-group">
                        <a class="minibutton tooltipped leftwards"
                           title="Clicking this button will automatically fork this project so you can edit the file"
                           href="/alexsleat/projectChimaera/edit/master/Drivers/vNavIMU/include/vNavIMU/vncp_services.h"
                           data-method="post" rel="nofollow">Edit</a>
                  <a href="/alexsleat/projectChimaera/raw/master/Drivers/vNavIMU/include/vNavIMU/vncp_services.h" class="button minibutton " id="raw-url">Raw</a>
                    <a href="/alexsleat/projectChimaera/blame/master/Drivers/vNavIMU/include/vNavIMU/vncp_services.h" class="button minibutton ">Blame</a>
                  <a href="/alexsleat/projectChimaera/commits/master/Drivers/vNavIMU/include/vNavIMU/vncp_services.h" class="button minibutton " rel="nofollow">History</a>
                </div><!-- /.button-group -->
              </div><!-- /.actions -->

            </div>
                <div class="blob-wrapper data type-c js-blob-data">
      <table class="file-code file-diff">
        <tr class="file-code-line">
          <td class="blob-line-nums">
            <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>

          </td>
          <td class="blob-line-code">
                  <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/**</span></div><div class='line' id='LC2'><span class="cm"> * \cond INCLUDE_PRIVATE</span></div><div class='line' id='LC3'><span class="cm"> * \file</span></div><div class='line' id='LC4'><span class="cm"> *</span></div><div class='line' id='LC5'><span class="cm"> * \section LICENSE</span></div><div class='line' id='LC6'><span class="cm"> * MIT License (MIT)</span></div><div class='line' id='LC7'><span class="cm"> *</span></div><div class='line' id='LC8'><span class="cm"> * Copyright (c) 2011 VectorNav Technologies, LLC</span></div><div class='line' id='LC9'><span class="cm"> *</span></div><div class='line' id='LC10'><span class="cm"> * Permission is hereby granted, free of charge, to any person obtaining a copy</span></div><div class='line' id='LC11'><span class="cm"> * of this software and associated documentation files (the &quot;Software&quot;), to</span></div><div class='line' id='LC12'><span class="cm"> * deal in the Software without restriction, including without limitation the</span></div><div class='line' id='LC13'><span class="cm"> * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or</span></div><div class='line' id='LC14'><span class="cm"> * sell copies of the Software, and to permit persons to whom the Software is</span></div><div class='line' id='LC15'><span class="cm"> * furnished to do so, subject to the following conditions:</span></div><div class='line' id='LC16'><span class="cm"> *</span></div><div class='line' id='LC17'><span class="cm"> * The above copyright notice and this permission notice shall be included in</span></div><div class='line' id='LC18'><span class="cm"> * all copies or substantial portions of the Software.</span></div><div class='line' id='LC19'><span class="cm"> *</span></div><div class='line' id='LC20'><span class="cm"> * THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR</span></div><div class='line' id='LC21'><span class="cm"> * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,</span></div><div class='line' id='LC22'><span class="cm"> * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE</span></div><div class='line' id='LC23'><span class="cm"> * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER</span></div><div class='line' id='LC24'><span class="cm"> * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING</span></div><div class='line' id='LC25'><span class="cm"> * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS</span></div><div class='line' id='LC26'><span class="cm"> * IN THE SOFTWARE.</span></div><div class='line' id='LC27'><span class="cm"> *</span></div><div class='line' id='LC28'><span class="cm"> * \section DESCRIPTION</span></div><div class='line' id='LC29'><span class="cm"> * This header file provides access to the cross-platform services for the</span></div><div class='line' id='LC30'><span class="cm"> * VectorNav C/C++ Library.</span></div><div class='line' id='LC31'><span class="cm"> */</span></div><div class='line' id='LC32'><span class="cp">#ifndef _VNCP_SERVICES_H_</span></div><div class='line' id='LC33'><span class="cp">#define _VNCP_SERVICES_H_</span></div><div class='line' id='LC34'><br/></div><div class='line' id='LC35'><span class="cp">#ifdef WIN32</span></div><div class='line' id='LC36'>	<span class="err">#</span><span class="n">include</span> <span class="o">&lt;</span><span class="n">Windows</span><span class="p">.</span><span class="n">h</span><span class="o">&gt;</span></div><div class='line' id='LC37'><span class="cp">#endif</span></div><div class='line' id='LC38'><span class="cp">#ifdef __linux__</span></div><div class='line' id='LC39'>	<span class="err">#</span><span class="n">include</span> <span class="o">&lt;</span><span class="n">pthread</span><span class="p">.</span><span class="n">h</span><span class="o">&gt;</span></div><div class='line' id='LC40'><span class="cp">#endif</span></div><div class='line' id='LC41'><br/></div><div class='line' id='LC42'><span class="cp">#include &quot;vn_errorCodes.h&quot;</span></div><div class='line' id='LC43'><br/></div><div class='line' id='LC44'><span class="cp">#ifdef __cplusplus</span></div><div class='line' id='LC45'><span class="k">extern</span> <span class="s">&quot;C&quot;</span> <span class="p">{</span></div><div class='line' id='LC46'><span class="cp">#endif</span></div><div class='line' id='LC47'><br/></div><div class='line' id='LC48'><span class="cp">#define VN_NULL ((void *) 0)</span></div><div class='line' id='LC49'><span class="cp">#define VN_TRUE ((VN_BOOL) 1)</span></div><div class='line' id='LC50'><span class="cp">#define VN_FALSE ((VN_BOOL) 0)</span></div><div class='line' id='LC51'><br/></div><div class='line' id='LC52'><span class="k">typedef</span> <span class="kt">char</span> <span class="n">VN_BOOL</span><span class="p">;</span></div><div class='line' id='LC53'><br/></div><div class='line' id='LC54'><span class="cp">#ifdef WIN32</span></div><div class='line' id='LC55'>	<span class="k">typedef</span> <span class="n">HANDLE</span>				<span class="n">VN_HANDLE</span><span class="p">;</span></div><div class='line' id='LC56'>	<span class="k">typedef</span> <span class="n">CRITICAL_SECTION</span>	<span class="n">VN_CRITICAL_SECTION</span><span class="p">;</span></div><div class='line' id='LC57'><span class="cp">#elif __linux__</span></div><div class='line' id='LC58'>	<span class="k">typedef</span>	<span class="k">union</span> <span class="p">{</span></div><div class='line' id='LC59'>		<span class="kt">pthread_t</span>			<span class="n">pThreadHandle</span><span class="p">;</span></div><div class='line' id='LC60'>		<span class="kt">int</span>					<span class="n">comPortHandle</span><span class="p">;</span></div><div class='line' id='LC61'>		<span class="kt">pthread_mutex_t</span>		<span class="n">mutexHandle</span><span class="p">;</span></div><div class='line' id='LC62'>		<span class="kt">void</span><span class="o">*</span>				<span class="n">conditionAndMutexStruct</span><span class="p">;</span></div><div class='line' id='LC63'>	<span class="p">}</span> <span class="n">VN_HANDLE</span><span class="p">;</span></div><div class='line' id='LC64'>	<span class="k">typedef</span> <span class="kt">pthread_mutex_t</span>	<span class="n">VN_CRITICAL_SECTION</span><span class="p">;</span></div><div class='line' id='LC65'><span class="cp">#endif</span></div><div class='line' id='LC66'><br/></div><div class='line' id='LC67'><span class="k">typedef</span> <span class="kt">void</span> <span class="o">*</span><span class="p">(</span><span class="o">*</span><span class="n">VN_THREAD_START_ROUTINE</span><span class="p">)(</span><span class="kt">void</span><span class="o">*</span><span class="p">);</span></div><div class='line' id='LC68'><br/></div><div class='line' id='LC69'><span class="cm">/**</span></div><div class='line' id='LC70'><span class="cm"> * \brief Creates a new thread.</span></div><div class='line' id='LC71'><span class="cm"> *</span></div><div class='line' id='LC72'><span class="cm"> * \param[out]	newThreadHandle		Handle of the newly created thread.</span></div><div class='line' id='LC73'><span class="cm"> * \param[in]	startRoutine		Pointer to the routine the new thread should execute.</span></div><div class='line' id='LC74'><span class="cm"> * \param[in]	routineData			Pointer to data that will be passed to the new thread&#39;s execution routine.</span></div><div class='line' id='LC75'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC76'><span class="cm"> */</span></div><div class='line' id='LC77'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_thread_startNew</span><span class="p">(</span><span class="n">VN_HANDLE</span><span class="o">*</span> <span class="n">newThreadHandle</span><span class="p">,</span> <span class="n">VN_THREAD_START_ROUTINE</span> <span class="n">startRoutine</span><span class="p">,</span> <span class="kt">void</span><span class="o">*</span> <span class="n">routineData</span><span class="p">);</span></div><div class='line' id='LC78'><br/></div><div class='line' id='LC79'><span class="cm">/**</span></div><div class='line' id='LC80'><span class="cm"> * \brief Opens a COM port.</span></div><div class='line' id='LC81'><span class="cm"> *</span></div><div class='line' id='LC82'><span class="cm"> * \param[out]	newComPortHandle	Handle to the newly opened COM port.</span></div><div class='line' id='LC83'><span class="cm"> * \param[in]	portName			The name of the COM port to open.</span></div><div class='line' id='LC84'><span class="cm"> * \param[in]	baudrate			The baudrate to communicate at.</span></div><div class='line' id='LC85'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC86'><span class="cm"> */</span></div><div class='line' id='LC87'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_open</span><span class="p">(</span><span class="n">VN_HANDLE</span><span class="o">*</span> <span class="n">newComPortHandle</span><span class="p">,</span> <span class="kt">char</span> <span class="k">const</span><span class="o">*</span> <span class="n">portName</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">baudrate</span><span class="p">);</span></div><div class='line' id='LC88'><br/></div><div class='line' id='LC89'><span class="cm">/**</span></div><div class='line' id='LC90'><span class="cm"> * \brief Write data out of a COM port.</span></div><div class='line' id='LC91'><span class="cm"> *</span></div><div class='line' id='LC92'><span class="cm"> * \param[in]	comPortHandle		Handle to an open COM port.</span></div><div class='line' id='LC93'><span class="cm"> * \param[in]	dataToWrite			Pointer to array of bytes to write out the COM port.</span></div><div class='line' id='LC94'><span class="cm"> * \param[in]	numOfBytesToWrite	The number of bytes to write from the dataToWrite pointer.</span></div><div class='line' id='LC95'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC96'><span class="cm"> */</span></div><div class='line' id='LC97'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_writeData</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">comPortHandle</span><span class="p">,</span> <span class="kt">char</span> <span class="k">const</span><span class="o">*</span> <span class="n">dataToWrite</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfBytesToWrite</span><span class="p">);</span></div><div class='line' id='LC98'><br/></div><div class='line' id='LC99'><span class="cm">/**</span></div><div class='line' id='LC100'><span class="cm"> * \brief Reads data from a COM port. Will block temporarily for a short amount</span></div><div class='line' id='LC101'><span class="cm"> * of time and then return if no data has been received.</span></div><div class='line' id='LC102'><span class="cm"> *</span></div><div class='line' id='LC103'><span class="cm"> * \param[in]	comPortHandle			Handle to an open COM port.</span></div><div class='line' id='LC104'><span class="cm"> * \param[out]	readBuffer				Pointer to a buffer where data read from the COM port will be placed into.</span></div><div class='line' id='LC105'><span class="cm"> * \param[in]	numOfBytesToRead		The number of bytes to attempt reading from the COM port.</span></div><div class='line' id='LC106'><span class="cm"> * \param[out]	numOfBytesActuallyRead	The number of bytes actually read from the COM port during the read attempt.</span></div><div class='line' id='LC107'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC108'><span class="cm"> */</span></div><div class='line' id='LC109'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_readData</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">comPortHandle</span><span class="p">,</span> <span class="kt">char</span><span class="o">*</span> <span class="n">readBuffer</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfBytesToRead</span><span class="p">,</span> <span class="kt">unsigned</span> <span class="kt">int</span><span class="o">*</span> <span class="n">numOfBytesActuallyRead</span><span class="p">);</span></div><div class='line' id='LC110'><br/></div><div class='line' id='LC111'><span class="cm">/**</span></div><div class='line' id='LC112'><span class="cm"> * \brief Closes the COM port.</span></div><div class='line' id='LC113'><span class="cm"> *</span></div><div class='line' id='LC114'><span class="cm"> * \param[in]	comPortHandle	Handle to an open COM port.</span></div><div class='line' id='LC115'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC116'><span class="cm"> */</span></div><div class='line' id='LC117'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_comPort_close</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">comPortHandle</span><span class="p">);</span></div><div class='line' id='LC118'><br/></div><div class='line' id='LC119'><span class="cm">/**</span></div><div class='line' id='LC120'><span class="cm"> * \brief Creates a new event.</span></div><div class='line' id='LC121'><span class="cm"> *</span></div><div class='line' id='LC122'><span class="cm"> * \param[out]	newEventHandle	Returns the handle of the newly created event.</span></div><div class='line' id='LC123'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC124'><span class="cm"> */</span></div><div class='line' id='LC125'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_event_create</span><span class="p">(</span><span class="n">VN_HANDLE</span><span class="o">*</span> <span class="n">newEventHandle</span><span class="p">);</span></div><div class='line' id='LC126'><br/></div><div class='line' id='LC127'><span class="cm">/**</span></div><div class='line' id='LC128'><span class="cm"> * \brief Causes the calling thread to wait on an event until the event is signalled.</span></div><div class='line' id='LC129'><span class="cm"> *</span></div><div class='line' id='LC130'><span class="cm"> * \param[in]	eventHandle		Handle to the event.</span></div><div class='line' id='LC131'><span class="cm"> * \param[in]	timeout			The number of milliseconds to wait before the</span></div><div class='line' id='LC132'><span class="cm"> * thread stops listening. -1 indicates that the wait time is inifinite. If a</span></div><div class='line' id='LC133'><span class="cm"> * timeout does occur, the value VNERR_TIMEOUT will be retured.</span></div><div class='line' id='LC134'><span class="cm"> *</span></div><div class='line' id='LC135'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC136'><span class="cm"> */</span></div><div class='line' id='LC137'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_event_waitFor</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">eventHandle</span><span class="p">,</span> <span class="kt">int</span> <span class="n">timeout</span><span class="p">);</span></div><div class='line' id='LC138'><br/></div><div class='line' id='LC139'><span class="cm">/**</span></div><div class='line' id='LC140'><span class="cm"> * \brief Puts the provided event into a signalled state.</span></div><div class='line' id='LC141'><span class="cm"> *</span></div><div class='line' id='LC142'><span class="cm"> * \param[in]	eventHandle		Handle to the event.</span></div><div class='line' id='LC143'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC144'><span class="cm"> */</span></div><div class='line' id='LC145'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_event_signal</span><span class="p">(</span><span class="n">VN_HANDLE</span> <span class="n">eventHandle</span><span class="p">);</span></div><div class='line' id='LC146'><br/></div><div class='line' id='LC147'><span class="cm">/**</span></div><div class='line' id='LC148'><span class="cm"> * \brief Initializes a new critical section object.</span></div><div class='line' id='LC149'><span class="cm"> *</span></div><div class='line' id='LC150'><span class="cm"> * \param[out]	criticalSection		Returns the newly initialized created critical control object.</span></div><div class='line' id='LC151'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC152'><span class="cm"> */</span></div><div class='line' id='LC153'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_initialize</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">);</span></div><div class='line' id='LC154'><br/></div><div class='line' id='LC155'><span class="cm">/**</span></div><div class='line' id='LC156'><span class="cm"> * \brief Attempt to enter a critical section.</span></div><div class='line' id='LC157'><span class="cm"> *</span></div><div class='line' id='LC158'><span class="cm"> * \param[in]	criticalSection		Pointer to the critical section control object.</span></div><div class='line' id='LC159'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC160'><span class="cm"> */</span></div><div class='line' id='LC161'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_enter</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">);</span></div><div class='line' id='LC162'><br/></div><div class='line' id='LC163'><span class="cm">/**</span></div><div class='line' id='LC164'><span class="cm"> * \brief Signals that the current executing thread is leaving the critical section.</span></div><div class='line' id='LC165'><span class="cm"> *</span></div><div class='line' id='LC166'><span class="cm"> * \param[in]	criticalSection		Pointer to the critical section control object.</span></div><div class='line' id='LC167'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC168'><span class="cm"> */</span></div><div class='line' id='LC169'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_leave</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">);</span></div><div class='line' id='LC170'><br/></div><div class='line' id='LC171'><span class="cm">/**</span></div><div class='line' id='LC172'><span class="cm"> * \brief Disposes and frees the resources associated with a critical section control object.</span></div><div class='line' id='LC173'><span class="cm"> *</span></div><div class='line' id='LC174'><span class="cm"> * \param[in]	criticalSection		Pointer to the critical section control object.</span></div><div class='line' id='LC175'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC176'><span class="cm"> */</span></div><div class='line' id='LC177'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_criticalSection_dispose</span><span class="p">(</span><span class="n">VN_CRITICAL_SECTION</span><span class="o">*</span> <span class="n">criticalSection</span><span class="p">);</span></div><div class='line' id='LC178'><br/></div><div class='line' id='LC179'><span class="cm">/**</span></div><div class='line' id='LC180'><span class="cm"> * \brief Sleeps the current thread the specified number of milliseconds.</span></div><div class='line' id='LC181'><span class="cm"> *</span></div><div class='line' id='LC182'><span class="cm"> * \param[in]	numOfMillisecondsToSleep	The number of milliseconds to pause the current thread.</span></div><div class='line' id='LC183'><span class="cm"> * \return VectorNav error code.</span></div><div class='line' id='LC184'><span class="cm"> */</span></div><div class='line' id='LC185'><span class="n">VN_ERROR_CODE</span> <span class="nf">vncp_sleepInMs</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">numOfMillisecondsToSleep</span><span class="p">);</span></div><div class='line' id='LC186'><br/></div><div class='line' id='LC187'><span class="cp">#ifdef __cplusplus</span></div><div class='line' id='LC188'><span class="p">}</span></div><div class='line' id='LC189'><span class="cp">#endif</span></div><div class='line' id='LC190'><br/></div><div class='line' id='LC191'><span class="cp">#endif </span><span class="cm">/* _VNCP_SERVICES_H_ */</span><span class="cp"></span></div><div class='line' id='LC192'><br/></div><div class='line' id='LC193'><span class="cm">/** \endcond */</span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>

        <a href="#jump-to-line" rel="facebox" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
        <div id="jump-to-line" style="display:none">
          <h2>Jump to Line</h2>
          <form accept-charset="UTF-8" class="js-jump-to-line-form">
            <input class="textfield js-jump-to-line-field" type="text">
            <div class="full-button">
              <button type="submit" class="button">Go</button>
            </div>
          </form>
        </div>

      </div>
    </div>
</div>

<div id="js-frame-loading-template" class="frame frame-loading large-loading-area" style="display:none;">
  <img class="js-frame-loading-spinner" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-128.gif?1347543527" height="64" width="64">
</div>


        </div>
      </div>
      <div class="modal-backdrop"></div>
    </div>

      <div id="footer-push"></div><!-- hack for sticky footer -->
    </div><!-- end of wrapper - hack for sticky footer -->

      <!-- footer -->
      <div id="footer">
  <div class="container clearfix">

      <dl class="footer_nav">
        <dt>GitHub</dt>
        <dd><a href="https://github.com/about">About us</a></dd>
        <dd><a href="https://github.com/blog">Blog</a></dd>
        <dd><a href="https://github.com/contact">Contact &amp; support</a></dd>
        <dd><a href="http://enterprise.github.com/">GitHub Enterprise</a></dd>
        <dd><a href="http://status.github.com/">Site status</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Applications</dt>
        <dd><a href="http://mac.github.com/">GitHub for Mac</a></dd>
        <dd><a href="http://windows.github.com/">GitHub for Windows</a></dd>
        <dd><a href="http://eclipse.github.com/">GitHub for Eclipse</a></dd>
        <dd><a href="http://mobile.github.com/">GitHub mobile apps</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Services</dt>
        <dd><a href="http://get.gaug.es/">Gauges: Web analytics</a></dd>
        <dd><a href="http://speakerdeck.com">Speaker Deck: Presentations</a></dd>
        <dd><a href="https://gist.github.com">Gist: Code snippets</a></dd>
        <dd><a href="http://jobs.github.com/">Job board</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Documentation</dt>
        <dd><a href="http://help.github.com/">GitHub Help</a></dd>
        <dd><a href="http://developer.github.com/">Developer API</a></dd>
        <dd><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></dd>
        <dd><a href="http://pages.github.com/">GitHub Pages</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>More</dt>
        <dd><a href="http://training.github.com/">Training</a></dd>
        <dd><a href="https://github.com/edu">Students &amp; teachers</a></dd>
        <dd><a href="http://shop.github.com">The Shop</a></dd>
        <dd><a href="/plans">Plans &amp; pricing</a></dd>
        <dd><a href="http://octodex.github.com/">The Octodex</a></dd>
      </dl>

      <hr class="footer-divider">


    <p class="right">&copy; 2013 <span title="0.12491s from fe16.rs.github.com">GitHub</span>, Inc. All rights reserved.</p>
    <a class="left" href="https://github.com/">
      <span class="mega-icon mega-icon-invertocat"></span>
    </a>
    <ul id="legal">
        <li><a href="https://github.com/site/terms">Terms of Service</a></li>
        <li><a href="https://github.com/site/privacy">Privacy</a></li>
        <li><a href="https://github.com/security">Security</a></li>
    </ul>

  </div><!-- /.container -->

</div><!-- /.#footer -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
          <div class="suggester-container">
              <div class="suggester fullscreen-suggester js-navigation-container" id="fullscreen_suggester"
                 data-url="/alexsleat/projectChimaera/suggestions/commit">
              </div>
          </div>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped leftwards" title="Exit Zen Mode">
      <span class="mega-icon mega-icon-normalscreen"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped leftwards"
      title="Switch themes">
      <span class="mini-icon mini-icon-brightness"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="mini-icon mini-icon-exclamation"></span>
      Something went wrong with that request. Please try again.
      <a href="#" class="mini-icon mini-icon-remove-close ajax-error-dismiss"></a>
    </div>

    
    
    <span id='server_response_time' data-time='0.12548' data-host='fe16'></span>
    
  </body>
</html>

